#include "gtest/gtest.h"

#include "utility/Pool.hpp"

class Object {
    public:
        using id = size_t;
        Object() : value(0) {;}
        Object(const int& newValue) : value(newValue) {;}
        int value;
}; 

TEST(PoolTests, pool_works_fine) {
    p2d::utility::Pool<Object, 100> pool;

    EXPECT_TRUE(pool.empty());
    EXPECT_EQ(pool.size(), 0);
    EXPECT_EQ(pool.capacity(), 100);

    EXPECT_EQ(pool.numFreeIndexes(), 0);
}