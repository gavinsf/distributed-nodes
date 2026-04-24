#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include <asio.hpp>
#include <memory>
#include "TcpServer.h"
#include <thread>

using asio::ip::tcp;

class node
{
    private:
    asio::io_context context_;
    tcp::resolver resolver_;
    std::unique_ptr<tcp_server> p_server;
    size_t id;
    size_t port;
    std::unordered_map<size_t, std::pair<size_t, size_t>> membership;
    size_t n;
    size_t r_quorum;
    size_t w_quorum;
    std::thread worker_thread;

    public:
    node(size_t id, size_t n, size_t r_quorum, size_t w_quorum);
    ~node();
    void start();
    size_t get_port();
};