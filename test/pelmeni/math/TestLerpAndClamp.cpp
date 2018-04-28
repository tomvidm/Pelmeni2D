#include "gtest/gtest.h"

#include "math/ClampedValue.hpp"
#include "math/LinearInterpolation.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestLerpAndClamp, ClampWorksFine) {
        ClampedValue<float> v1(-0.5f, 0.f, 1.f);
        ClampedValue<float> v2(0.5f, 0.f, 1.f);
        ClampedValue<float> v3(1.5f, 0.f, 1.f);
        EXPECT_EQ(v1.get(), 0.f);
        EXPECT_EQ(v2.get(), 0.5f);
        EXPECT_EQ(v3.get(), 1.f);
    }

    TEST(TestMath, LerpWorksFine) {
        LinearInterpolation<float> lerp(50.f, 100.f);
        EXPECT_EQ(lerp.getInterpolated(-0.5f), 50.f);
        EXPECT_EQ(lerp.getInterpolated(0.f), 50.f);
        EXPECT_EQ(lerp.getInterpolated(0.5f), 75.f);
        EXPECT_EQ(lerp.getInterpolated(1.f), 100.f);
        EXPECT_EQ(lerp.getInterpolated(1.5f), 100.f);
    }
}
}
}