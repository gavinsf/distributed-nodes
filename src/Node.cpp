#include "Node.h"
#include <asio.hpp>
#include "TcpServer.h"

using asio::ip::tcp;


node::node(size_t id, size_t n, size_t r_quorum, size_t w_quorum)
    : id(id),
      n(n),
      r_quorum(r_quorum),
      w_quorum(w_quorum),
      context()
{
    port = -1;
    auto work = asio::make_work_guard(context);
}

node::~node()
{
    context.stop();
}

void node::start()
{
    // Check if there is a node on 3000
    // 
    try 
    {
        p_server = std::make_unique<tcp_server>(context, 3000);
        port = 3000;

    }
    catch (const std::system_error& e)
    {
        if (e.code() == std::errc::address_in_use)
        {
            p_server = std::make_unique<tcp_server>(context, 0);
            if (p_server)
                port = p_server->get_port();
        }
        
    }
    context.run();
}

size_t node::get_port()
{
    return port;
}