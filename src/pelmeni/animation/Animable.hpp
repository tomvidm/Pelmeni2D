#pragma once

#include <memory>

#include "math/BezierCurve.hpp"
#include "system/Transformable2.hpp"
#include "animation/Animation.hpp"

namespace p2d { namespace animation {
    class Animable
    : public system::Transformable2 {
    public:
        void updateAnimation(const sf::Time dt);
        void setAnimation(const Animation& anim);
        Animation animation;
    }; // class Animable
} // namespace animation
} // namespace p2d