#include "TcpServer.h"
#include "TcpConnection.h"

tcp_server::tcp_server(asio::io_context& io_context, size_t port)
    :  io_context(io_context);
       acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{

}

void tcp_server::listener()
{
    tcp_connection::pointer new_connection =
        tcp_connection::create(io_context);
    
    acceptor.async_accept(new_connection->socket(),
        std::bind(&tcp_server::handle_accept, this, new_connection,
            asio::placeholders::error));
}

void tcp_server::handler(tcp_connection::pointer new_connection, const std::error_code& error)
{
    if (!error)
    {
        new_connection->start();
    }

    listener();
}