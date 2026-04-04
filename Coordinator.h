#include <map>
#include "Node.h"

class Coordinator
{
    private:
    std::map<size_t, Node> nodes;
    size_t n;
    size_t r_quorum;
    size_t w_quorum;

    public:
    Coordinator(size_t n, size_t r_quorum, size_t w_quorum);
};