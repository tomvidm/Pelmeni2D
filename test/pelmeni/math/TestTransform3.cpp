#include <math.h>

#include "gtest/gtest.h"

#include "math/Transform3.hpp"
#include "math/Vector.hpp"

#include "../Helpers.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestMath, Transform3WorksFine) {
        const float pi = 3.141592f;
        Transform3 translate = Transform3::Translation(1.f, 1.f, 1.f);

        Vector3f u(1.f, 1.f, 1.f);
        Vector3f v(1.f, 1.f, 0.f);

        EXPECT_EQ(translate.transformPoint(0.f, 0.f, 0.f), Vector3f(1.f, 1.f, 1.f));

        Vector3f a(1.f, 1.f, 1.f); // axis
        const Transform3 t = Transform3::Rotation(a, M_PI/4);
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[0], 0.8047379f));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[1], -0.3106172f));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[2], 0.5058793f));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[4], 0.5058793));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[5], 0.8047379));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[6], -0.3106172));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[8], -0.3106172));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[9], 0.5058793));
        EXPECT_TRUE(p2d::ut::floatCompare(t.mat[10], 0.8047379));


    }
}
}
}