#include <gtest/gtest.h>
#include "Node.h"

TEST(TestNode, FirstCreation)
{
    size_t id = 1;
    size_t n = 1;
    size_t r_quorum = 1;
    size_t w_quorum = 1;
    node node{id, n, r_quorum, w_quorum};
    node.start();
    EXPECT_EQ(node.get_port(), 3000);
}