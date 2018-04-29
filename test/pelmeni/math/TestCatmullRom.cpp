#include "gtest/gtest.h"

#include <vector>

#include "math/CatmullRomSpline.hpp"
#include "math/CatmullRomInterpolator.hpp"
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
    EXPECT_EQ(spline.generatePointOnCurve(0.f).x, math::Vector2f(0.f, 0.f).x);
    EXPECT_EQ(spline.generatePointOnCurve(1.f).x, math::Vector2f(100.f, 100.f).x);
}

TEST(TestMath, catmull_rom_interpolator) {
    using namespace p2d;
    std::vector<math::Vector2f> cps {
        {0.f, 0.f},
        {100.f, 100.f},
        {200.f, 100.f},
        {200.f, 200.f},
        {100.f, 200.f}
    };

    math::CatmullRomInterpolator<math::Vector2f> cri(cps, 0);
    EXPECT_EQ(cri.getInterpolated(0.f), math::Vector2f(0.f, 0.f));
    EXPECT_EQ(cri.getInterpolated(1.f), math::Vector2f(100.f, 100.f));
    cri.setControlPoints(cps, 1);
    EXPECT_EQ(cri.getInterpolated(0.f), math::Vector2f(100.f, 100.f));
    EXPECT_EQ(cri.getInterpolated(1.f), math::Vector2f(200.f, 100.f));
    cri.setControlPoints(cps, 2);
    EXPECT_EQ(cri.getInterpolated(0.f), math::Vector2f(200.f, 100.f));
    EXPECT_EQ(cri.getInterpolated(1.f), math::Vector2f(200.f, 200.f));
    cri.setControlPoints(cps, 3);
    EXPECT_EQ(cri.getInterpolated(0.f), math::Vector2f(200.f, 200.f));
    EXPECT_EQ(cri.getInterpolated(1.f), math::Vector2f(100.f, 200.f));
}