#include <memory>
#include <asio.hpp>
#include <string>

using asio::ip::tcp;

class tcp_connection
    : public std::enabled_shared_from_this<tcp_connection>
{
    private:
    tcp::socket socket_;
    std::string message_;
    tcp_connection(asio::io_context& io_context);
    void handle_write(const std::error_code&, size_t);

    public:
    typedef std::shared_ptr<tcp_connection> pointer;
    static pointer create(asio::io_context& io_context);
    tcp::socket& socket();
    void start(std::string message);
};