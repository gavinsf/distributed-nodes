#include "Node.h"
#include <asio.hpp>


Node::Node(size_t id, size_t n, size_t rQuorum, size_t wQuorum)
    : id(id),
      n(n),
      rQuorum(rQuorum),
      wQuorum(wQuorum),
      context()
{
    auto work = asio::make_work_guard(context);
    start();
}

void Node::start()
{
    context.run();
}
