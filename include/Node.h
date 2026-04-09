#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include <asio.hpp>
#include <memory>
#include "TcpServer.h"

using asio::ip::tcp;

class node
{
    private:
    size_t id;
    size_t port;
    asio::io_context context;
    std::unordered_map<size_t, std::pair<size_t, size_t>> membership;
    size_t n;
    size_t r_quorum;
    size_t w_quorum;
    std::unique_ptr<tcp_server> server;

    public:
    node(size_t id, size_t port, size_t n, size_t r_quorum, size_t w_quorum);
    void start();
};