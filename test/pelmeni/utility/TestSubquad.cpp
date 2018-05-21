#include "gtest/gtest.h"

#include "utility/Subquad.hpp"
#include "math/Vector.hpp"

#include <iostream>

struct Object {
    p2d::math::Vector2f position;

    p2d::math::Vector2f getPosition() const { return position; }
};

TEST(TestUtilities, subquad_works) {
    p2d::utility::Subquad<Object> sq(4, {{0.f, 0.f}, {100.f, 100.f}});;
    sq.push(Object{{25.f, 25.f}});
    EXPECT_EQ(sq.count(), 1);
    sq.push(Object{{75.f, 25.f}});
    EXPECT_EQ(sq.count(), 2);
    sq.push(Object{{75.f, 75.f}});
    EXPECT_EQ(sq.count(), 3);
    sq.push(Object{{75.f, 75.f}});
    EXPECT_EQ(sq.count(), 4);
    sq.push(Object{{25.f, 75.f}});
    EXPECT_EQ(sq.count(), 0);

    EXPECT_EQ(sq.getSubquadById(0).count(), 1);
    EXPECT_EQ(sq.getSubquadById(1).count(), 1);
    EXPECT_EQ(sq.getSubquadById(2).count(), 2);
    EXPECT_EQ(sq.getSubquadById(3).count(), 1);
    EXPECT_EQ(sq.countTotal(), 5);
}