#include "TcpServer.h"
#include "TcpConnection.h"

tcp_server::tcp_server(asio::io_context& io_context, size_t port_)
    :  io_context(io_context),
       acceptor(io_context, tcp::endpoint(tcp::v4(), port_))
{
    port = acceptor.local_endpoint().port();
    listener();
}

tcp_server::~tcp_server()
{
    asio::error_code ec;

    acceptor.cancel(ec);
    acceptor.close(ec);
}

void tcp_server::listener()
{
    tcp_connection::pointer new_connection =
        tcp_connection::create(io_context);
    
    acceptor.async_accept(new_connection->socket(),
        std::bind(&tcp_server::handler, this, new_connection,
            asio::placeholders::error));
}

void tcp_server::handler(tcp_connection::pointer new_connection, const std::error_code& error)
{
    if (!error)
    {
        new_connection->start("TEMPORARY");
    }

    listener();
}

size_t tcp_server::get_port()
{
    return port;
}