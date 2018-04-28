#include "gtest/gtest.h"

#include <iostream>

#include "animation/Frame.hpp"
#include "math/LinearInterpolation.hpp"
#include "math/Vector.hpp"

TEST(TestAnimation, keyframe_interpolation_works) {
    using p2d::animation::Frame;
    using p2d::math::LinearInterpolation;

    Frame kf1{
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::fromRadians(0.f)
    };

    Frame kf2{
        p2d::math::Vector2f(100.f, 100.f),
        p2d::math::Vector2f(2.f, 2.f),
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::fromRadians(1.f)
    };

    LinearInterpolation<Frame> lerp(kf1, kf2);

    Frame expected_kf{
        p2d::math::Vector2f(50.f, 50.f),
        p2d::math::Vector2f(1.f, 1.f),
        p2d::math::Vector2f(0.f, 0.f),
        p2d::math::fromRadians(0.5f)
    };

    Frame actual_kf = lerp.getInterpolated(0.5f);
    EXPECT_EQ(
        actual_kf,
        expected_kf
    );


}