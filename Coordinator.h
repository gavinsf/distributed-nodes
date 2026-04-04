#include <map>
#include "Node.h"

class Coordinator
{
    private:
    std::map<size_t, Node> nodes;
    size_t n;
    size_t rQuorum;
    size_t wQuorum;

    public:
    Coordinator(size_t n, size_t rQuorum, size_t wQuorum);
    add
};