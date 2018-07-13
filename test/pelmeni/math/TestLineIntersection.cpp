#include "gtest/gtest.h"

#include "math/LineIntersection.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestMath, intersection) {
        Vector2f u0(0.f, 0.f);
        Vector2f u1(3.f, 3.f);
        Vector2f v0(3.f, 0.f);
        Vector2f v1(0.f, 3.f);

        EXPECT_TRUE(linesIntersect(u0, u1, v0, v1));
        EXPECT_TRUE(linesIntersect(u1, u0, v0, v1));
        EXPECT_FALSE(linesIntersect(u0, v0, u1, v1));
        EXPECT_FALSE(linesIntersect(u0, 0.25f * u1, v0, v1));
    }
}
}
}