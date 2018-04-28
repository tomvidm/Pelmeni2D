#include "gtest/gtest.h"

#include <iostream>

#include "animation/Animation.hpp"
#include "math/LinearInterpolation.hpp"
#include "math/Vector.hpp"

TEST(TestAnimation, animation_interpolation_works) {
    using p2d::animation::Frame;
    using p2d::animation::Keyframe;
    using p2d::animation::Animation;

    Keyframe kf1{
        sf::seconds(1.f),
        Frame {
            p2d::math::Vector2f(0.f, 0.f),
            p2d::math::Vector2f(0.f, 0.f),
            p2d::math::fromRadians(0.f)
        }
    };

    Keyframe kf2{
        sf::seconds(1.f),
        Frame {
            p2d::math::Vector2f(100.f, 100.f),
            p2d::math::Vector2f(1.f, 1.f),
            p2d::math::fromRadians(1.f)
        }
    };

    Keyframe kf3{
        sf::seconds(1.f),
        Frame {
            p2d::math::Vector2f(0.f, 0.f),
            p2d::math::Vector2f(1.f, 1.f),
            p2d::math::fromRadians(1.f)
        }
    };

    std::vector<Keyframe> keyframes = {kf1, kf2, kf3, kf3};
    Animation anim(keyframes);

    Frame expected_frame1{
        p2d::math::Vector2f(50.f, 50.f),
        p2d::math::Vector2f(0.5f, 0.5f),
        p2d::math::fromRadians(0.5f)
    };

    Frame expected_frame2{
        p2d::math::Vector2f(100.f, 100.f),
        p2d::math::Vector2f(1.f, 1.f),
        p2d::math::fromRadians(1.f)
    };

    Frame expected_frame3{
        p2d::math::Vector2f(50.f, 50.f),
        p2d::math::Vector2f(1.f, 1.f),
        p2d::math::fromRadians(1.f)
    };
    anim.update(sf::seconds(0.f));
    EXPECT_EQ(anim.getCurrentKeyframeIndex(), 0);
    EXPECT_EQ(anim.getCurrentFrame(), kf1.frame);
    anim.update(sf::seconds(0.5f));
    EXPECT_EQ(anim.getCurrentKeyframeIndex(), 0);
    EXPECT_EQ(anim.getCurrentFrame(), expected_frame1);
    anim.update(sf::seconds(0.5f));
    EXPECT_EQ(anim.getCurrentKeyframeIndex(), 1);
    EXPECT_EQ(anim.getCurrentFrame(), expected_frame2);
    anim.update(sf::seconds(0.5f));
    EXPECT_EQ(anim.getCurrentKeyframeIndex(), 1);
    EXPECT_EQ(anim.getCurrentFrame(), expected_frame3);
}