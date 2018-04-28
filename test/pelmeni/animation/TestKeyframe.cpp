#include "gtest/gtest.h"

#include <iostream>

#include "animation/Keyframe.hpp"
#include "math/LinearInterpolation.hpp"
#include "math/Vector.hpp"

TEST(TestAnimation, keyframe_interpolation_works) {
    using p2d::animation::Keyframe;
    using p2d::math::LinearInterpolation;

    Keyframe kf1{
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::fromRadians(0.f)
    };

    Keyframe kf2{
        p2d::math::Vector2f(100.f, 100.f),
        p2d::math::Vector2f(2.f, 2.f),
        p2d::math::fromRadians(1.f)
    };

    Keyframe expected_kf{
        p2d::math::Vector2f(50.f, 50.f),
        p2d::math::Vector2f(1.f, 1.f),
        p2d::math::fromRadians(0.5f)
    };

    LinearInterpolation<Keyframe> lerp(kf1, kf2);

    Keyframe actual_kf = lerp.getInterpolated(0.5f);
    EXPECT_EQ(
        actual_kf,
        expected_kf
    );


}