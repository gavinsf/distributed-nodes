#include <map>
#include <string>
#include "Node.h"

class HashRing
{
    private:
    std::map<int, size_t> ring;
    size_t replicas;

    public:
    HashRing(size_t replicas);
    void addNode(const string& node);

}