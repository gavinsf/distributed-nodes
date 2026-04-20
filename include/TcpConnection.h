#pragma once

#include <asio.hpp>
#include "TcpServer.h"


class tcp_connection
    : std::enable_from_shared_this<tcp_connection>
{
    private:
    tcp::socket socket_
    asio::io_context context_
    awaitable<void> reader();
    void stop();
    tcp_connection(tcp::socket socket_, tcp_server& server);

    public:
    void start();
}