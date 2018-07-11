#include "gtest/gtest.h"

#include "math/GeometrySelection.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestGeometrySelection, SnapsCorrectly) {
        Vector2f p0(0.f, 0.f);
        Vector2f p1(6.f, 2.f);
        float width = 1.f;
        float longitude = 1.f;
        
        Vector2f snapping(2.f, 1.f);
        Vector2f nonsnapping(2.f, 3.f);

        EXPECT_TRUE(snapsToLine(snapping, p0, p1, longitude, width));
        EXPECT_FALSE(snapsToLine(nonsnapping, p0, p1, longitude, width));
        EXPECT_FALSE(snapsToLine(Vector2f(0.f, 0.f), p0, p1, longitude, width));
    }
}
}
}