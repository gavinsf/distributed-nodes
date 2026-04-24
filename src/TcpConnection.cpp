#include <asio.hpp>
#include "TcpConnection.h"
#include "TcpServer.h"
#include <iostream>
#include <string>


tcp_connection::tcp_connection(tcp::socket socket, tcp_server& server)
    : socket_(std::move(socket)),
      server_(server)
{}

void tcp_connection::start()
{
    co_spawn(socket_.get_executor(),
        [self = shared_from_this()]{ return self->reader(); },
        asio::detached);
}

void tcp_connection::stop() 
{
    socket_.close();
}

asio::awaitable<void> tcp_connection::reader()
{
    try
    {
        std::string read_msg;
    
        std::size_t n = co_await asio::async_read_until(socket_,
            asio::dynamic_buffer(read_msg, 1024), "\n\n", asio::use_awaitable);

        server_.receive(read_msg.substr(0, n));
        
        socket_.shutdown(tcp::socket::shutdown_both);
        socket_.close();
    }
    catch (std::exception& e)
    {
        std::cerr << "Connection closed: " << e.what() << std::endl;
        stop();
    }
}