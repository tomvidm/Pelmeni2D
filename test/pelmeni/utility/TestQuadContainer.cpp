#include <type_traits>

#include "gtest/gtest.h"

#include "utility/QuadContainer.hpp"

TEST(TestUtilities, QuadContainerWorksFine) {
    using p2d::utility::QuadContainer;

    QuadContainer<int, 4> q;

    EXPECT_TRUE(q.isEmpty());
    EXPECT_FALSE(q.isFull());
    EXPECT_EQ(q.numElements(), 0);
    
    q.push(1);
    q.push(1);
    q.push(1);
    EXPECT_EQ(q.numElements(), 3);
    EXPECT_TRUE(q.push(1));
    EXPECT_EQ(q.numElements(), 4);
    EXPECT_FALSE(q.push(1));
    EXPECT_EQ(q.numElements(), 4);

    for (auto it = q.begin(); it != q.end(); it++) {
        EXPECT_EQ(*it, 1);
    }
}