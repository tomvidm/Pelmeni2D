#include "gtest/gtest.h"

#include <vector>

#include "math/CatmullRomSpline.hpp"
#include "math/Vector.hpp"

TEST(TestMath, catmull_rom_endpoints) {
    using namespace p2d;
    std::vector<math::Vector2f> cps {
        {0.f, 0.f},
        {100.f, 100.f},
        {200.f, 100.f},
        {200.f, 200.f}
    };

    math::CatmullRomSpline spline(cps);

    EXPECT_EQ(spline.getStart(), math::Vector2f(0.f, 0.f));
    EXPECT_EQ(spline.getEnd(), math::Vector2f(200.f, 200.f));
    EXPECT_EQ(spline.generatePointOnCurve(0.f).x, math::Vector2f(100.f, 100.f).x);
    EXPECT_EQ(spline.generatePointOnCurve(1.f).x, math::Vector2f(200.f, 100.f).x);
}