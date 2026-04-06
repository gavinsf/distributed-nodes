#include <memory>
#include <asio.hpp>
#include <string>

using asio::ip::tcp;

tcp_connection::tcp_connection(asio::io_context& io_context)
    : socket_(io_context)
{}

void tcp_connection::handle_write(const std::error_code&, size_t)
{}

static pointer tcp_connection::create(asio::io_context& i_context)
{
    return pointer(new tcp_connection(io_context));
}

tcp::socket& tcp_connection::socket()
{
    return socket_;
}

tcp_connection::start(std::string message)
{
    asio::async_write(socket_, asio::buffer(message),
        std::bind(&tcp_connection::handle_write, shared_from_this(),
            asio::placeholders::error,
            asio::placeholders::bytes_transferred));
}