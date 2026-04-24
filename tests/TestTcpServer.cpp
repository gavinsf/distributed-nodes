#include <gtest/gtest.h>
#include "TcpServer.h"
#include <asio.hpp>

TEST(TestTcpServer, Init)
{
    unsigned short port_ = 3000;
    asio::io_context context_;
    tcp_server server_{context_, port_};
    EXPECT_EQ(port_, server_.get_port());
}