#pragma once

#include <asio.hpp>
#include "TcpConnection.h"

class tcp_server
{
    private:
    void listener();
    void handler(tcp_connection::pointer new_connection, const std::error_code& error);
    asio::io_context& io_context;
    tcp::acceptor acceptor;
    size_t port;

    public:
    tcp_server(asio::io_context& io_context, size_t port_);
    ~tcp_server();
    size_t get_port();
};
