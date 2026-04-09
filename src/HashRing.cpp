#include "HashRing.h"
#include <functional>
#include <string>


int get_hash(std::string_view str)
{
    std::hash<std::string> hash_func;
    return hash_func(str);
}

hash_ring::hash_ring(size_t replicas) :
    replicas(replicas) {}

void hash_ring::add_node(const size_t& node_id)
{
    for (int i = 0; i < replicas; i++)
    {
        std::string temp = "server_" + to_string(node_id) + "_" + to_string(i);
        ring.emplace(hash, get_hash(temp));
    }
}