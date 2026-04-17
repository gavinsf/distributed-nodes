#include "HashRing.h"
#include <functional>
#include <string>


int hash_ring::get_hash(std::string_view str)
{
    std::hash<std::string_view> hash_func;
    return hash_func(str);
}

int hash_ring::next_node(int hash)
{
    if (ring.size() == 0)
        return -1;

    if (ring.upper_bound(hash) == ring.end())
        return ring.begin()->first;
    else
        return ring.upper_bound(hash)->first;
}

hash_ring::hash_ring(size_t replicas) :
    replicas(replicas) {}

void hash_ring::add_node(const size_t& node_id)
{
    for (int i = 0; i < replicas; i++)
    {
        std::string temp = "server_" + std::to_string(node_id) + "_" + std::to_string(i);
        ring.emplace(get_hash(temp), node_id);
    }
}

size_t hash_ring::add_key_value(std::string key, std::string value)
{
    int hash = get_hash(key);
    int next = next_node(hash);
    return ring.at(next);
}

size_t hash_ring::get_size()
{
    return ring.size();
}