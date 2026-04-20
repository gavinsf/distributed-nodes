#pragma once

#include <asio.hpp>
#include <unordered_map>
#include <string>


class tcp_server
{
    private:
    tcp::acceptor acceptor_;
    asio::io_context context_;
    tcp::socket socket_;
    unsigned short port_;
    std::unordered_map<size_t, std::string> key_val;
    asio::thread_pool pool_;

    public:
    tcp_server(asio::io_context& context, unsigned short port);
    ~tcp_server();
    asio::awaitable<void> listener();
    void start();
    void receive(std::string msg);
    void receive_key_val(std::string msg);
}