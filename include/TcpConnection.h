#pragma once

#include <asio.hpp>
#include "TcpServer.h"
#include <memory>


class tcp_connection
    : public std::enable_shared_from_this<tcp_connection>
{
    private:
    asio::io_context context_;
    tcp::socket socket_;
    tcp_server& server_;
    asio::awaitable<void> reader();
    void stop();
    

    public:
    void start();
    tcp_connection(tcp::socket socket, tcp_server& server);
};