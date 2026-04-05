#include <unordered_map>
#include <string>
#include <utility>
#include <asio.hpp>

class Node
{
    private:
    size_t id;
    asio::io_context context;
    std::unordered_map<std::string, std::string> pairs;
    std::unordered_map<size_t, std::pair<size_t, size_t>> membership;
    size_t n;
    size_t rQuorum;
    size_t wQuorum;

    public:
    Node(size_t id, size_t n, size_t rQuorum, size_t wQuorum);
    void start();
};