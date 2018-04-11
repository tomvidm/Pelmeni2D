#include "gtest/gtest.h"

#include "math/Quaternion.hpp"

#include "../Helpers.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestMath, QuaternionWorksFine) {
        Quaternion<float> q1(1.f, 0.f, 1.f, 0.f);
        Quaternion<float> q2(1.f, 0.5f, 0.5f, 0.75f);

        EXPECT_EQ(q1 * q2, Quaternion<float>(0.5f, 1.25f, 1.5f, 0.25f));

        Quaternion<float> q3(2.f, 1.f, -2.f, 5.f);

        EXPECT_EQ(q3 * q3, Quaternion<float>(-26.f, 4.f, -8.f, 20.f));
    }
}
}
}