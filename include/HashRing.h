#pragma once

#include <map>
#include <string>
#include "Node.h"

class hash_ring
{
    private:
    std::map<int, size_t> ring;
    size_t replicas;
    int get_hash(std::string_view str);
    size_t find_next_node(int hash);

    public:
    hash_ring(size_t replicas);
    void add_node(const string& node);
    size_t add_key_value(std::string key, std::string value);
};