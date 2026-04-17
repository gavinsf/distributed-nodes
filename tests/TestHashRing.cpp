#include <gtest/gtest.h>
#include "HashRing.h"

TEST(TestHashRing, EmptyRing)
{
    hash_ring hr{1};
    EXPECT_EQ(0, hr.get_size());
}

TEST(TestHashRing, LargeRing)
{
    hash_ring hr{100};
    hr.add_node(1);
    hr.add_node(2);
    hr.add_node(3);
    hr.add_node(4);
    hr.add_node(5);
    EXPECT_EQ(500, hr.get_size());
}