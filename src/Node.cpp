#include "Node.h"
#include <asio.hpp>
#include "TcpServer.h"
#include <thread>

using asio::ip::tcp;


node::node(size_t id, size_t n, size_t r_quorum, size_t w_quorum)
    : id(id),
      n(n),
      r_quorum(r_quorum),
      w_quorum(w_quorum),
      context_(),
      resolver_(context_)
{
    port = -1;
}

node::~node()
{
    context_.stop();
    if (worker_thread.joinable()) {
        worker_thread.join();
    }
}

void node::start()
{
    // Check if there is a node on 3000
    try 
    {
        p_server = std::make_unique<tcp_server>(context_, 3000);
        port = 3000;
    }
    catch (const std::system_error& e)
    {
        if (e.code() == std::errc::address_in_use)
        {
            p_server = std::make_unique<tcp_server>(context_, 0);
            if (p_server)
            {
                port = p_server->get_port();
            }
        }
        
    }
    worker_thread = std::thread([this]() {
        context_.run(); 
    });
}

size_t node::get_port()
{
    return port;
}