#include "gtest/gtest.h"

#include <vector>

#include "math/ConvexPolygon.hpp"
#include "math/Vector.hpp"

TEST(TestMath, convex_polygon) {
    using namespace p2d;

    std::vector<math::Vector2f> vectors = {
        {-2.f, -2.f},
        {2.f, -2.f},
        {2.f, 2.f},
        {-2.f, 2.f}
    };

    math::ConvexPolygon poly(vectors);

    math::Vector2f pointInside{
        0.f, 0.f
    };

    math::Vector2f pointOutside{
        3.f, 3.f
    };

    EXPECT_TRUE(poly.containsPoint(pointInside));
    EXPECT_FALSE(poly.containsPoint(pointOutside));
}