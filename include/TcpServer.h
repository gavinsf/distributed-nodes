#pragma once

#include <asio.hpp>
#include <unordered_map>
#include <string>

using asio::ip::tcp;

class tcp_server
{
    private:
    asio::io_context& context_;
    tcp::acceptor acceptor_;
    unsigned short port_;
    std::unordered_map<size_t, std::string> key_val;

    public:
    tcp_server(asio::io_context& context, unsigned short port);
    ~tcp_server();
    asio::awaitable<void> listener();
    void start();
    void receive(std::string msg);
    asio::awaitable<void> handle_key_val(std::string msg);
    unsigned short get_port();
};