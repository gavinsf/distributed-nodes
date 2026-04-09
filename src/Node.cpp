#include "Node.h"
#include <asio.hpp>
#include "TcpServer.h"

using asio::ip::tcp;


node::node(size_t id, size_t port, size_t n, size_t r_quorum, size_t w_quorum)
    : id(id),
      port(port),
      n(n),
      r_quorum(r_quorum),
      w_quorum(w_quorum),
      context()
{
    auto work = asio::make_work_guard(context);
    start();
}

void node::start()
{
    server = std::make_unique<tcp_server>(context, port);
    context.run();
}

