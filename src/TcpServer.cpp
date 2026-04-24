#include <asio.hpp>
#include "TcpServer.h"
#include "TcpConnection.h"
#include <iostream>


tcp_server::tcp_server(asio::io_context& context, unsigned short port)
    : context_(context),
      acceptor_(context, tcp::endpoint(tcp::v4(), port)),
      port_(port)
{
    start();
}

void tcp_server::start()
{
    co_spawn(context_,
          listener(),
          asio::detached);
}

asio::awaitable<void> tcp_server::listener()
{
    for (;;)
    {
    std::make_shared<tcp_connection>(
        co_await acceptor_.async_accept(asio::use_awaitable),
        *this
      )->start();
    }
}

void tcp_server::receive(std::string msg)
{
    if (std::string_view(msg).substr(0, 6) == "KEYVAL\n")
    {
        co_spawn(context_,
          handle_key_val(msg),
          asio::detached);
    }
       
}

asio::awaitable<void> tcp_server::handle_key_val(std::string msg)
{
    std::cout << "Handling key val pair" << std::endl;
    msg.erase(0, 6); // TODO: Refactor this
    size_t newline = msg.find("\n");
    if (newline != std::string::npos)
    {
        
        //key_val.insert_or_assign(
         //   msg.substr(0, newline-1),
           // msg.substr(newline+1, msg.length() - 2));
    }
    else
    {
        std::cout << "Newline char not found" << std::endl;
    }
    co_return;
}

tcp_server::~tcp_server()
{   
    context_.stop();
}

unsigned short tcp_server::get_port()
{
    return port_;
}
