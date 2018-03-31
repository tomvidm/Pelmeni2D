#include "gtest/gtest.h"

#include "utility/Pool.hpp"

#include <cstdio>

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

    EXPECT_EQ(pool.numFreedIndexes(), 0);

    {
        Object::id firstId = pool.push(Object(1));
        Object::id secondId = pool.push(Object(5));
        EXPECT_EQ(pool.size(), 2);
        EXPECT_EQ(firstId, 0);
        EXPECT_EQ(secondId, 1);
        pool.push(Object());
        pool.remove(firstId);
        pool.remove(secondId);
        pool.push(Object());
    }
    EXPECT_EQ(pool.numFreedIndexes(), 1);
    EXPECT_EQ(pool.size(), 2);
}