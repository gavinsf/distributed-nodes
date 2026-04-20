#include <asio.hpp>
#include "TcpServer.h"


tcp_server::tcp_server(asio::io_context& context, unsigned short port)
    : context_(context),
      acceptor_(context, tcp::endpoint(tcp::v4(), port)),
      port_(port),
      pool_(2)
{
    start();
}

void tcp_server::start()
{
    co_spawn(context_,
          listener(),
          detached);
}

asio::awaitable<void> listener()
{
    for (;;)
    {
    std::make_shared<chat_session>(
        co_await acceptor.async_accept(use_awaitable),
        room
      )->start();
    }
}

void tcp_server::receive(std::string msg)
{
    if (std::string_view(msg).substr(0, 6) == "KEYVAL\n")
    {
        asio::post(pool_, handle_key_val(msg))
    }
       
}

void handle_key_val(std::string& msg)
{
    std::cout << "Handling key val pair" << std::endl;
    msg.erase(0, 6);
    size_t newline = msg.find("\n");
    if (newline != std::string::npos)
    {
        key_val.insert_or_assign(
            msg.substr(0, newline-1),
            msg.substr(newline+1, msg.length));
    }
    else
    {
        std::cout << "Newline char not found" << std::endl;
    }
}

tcp_server::~tcp_server()
{
    pool_.stop()
    pool_.join()
    context_.destroy();
}