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
        void stopAnimation();
        void startAnimation();
        Animation animation;
    private:
        bool animationIsRunning = false;
    }; // class Animable
} // namespace animation
} // namespace p2d