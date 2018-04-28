#pragma once

#include <memory>

#include "math/BezierCurve.hpp"
#include "system/Transformable2.hpp"

#include "animation/Animation.hpp"


namespace p2d { namespace animation {
    class Animable
    : public system::Transformable2 {
    public:
        void update(const sf::Time dt);
        void setAnimation(Animation* animation);
    private:
        bool animationRunning = false;
        Animation* anim;
    }; // class Animable
} // namespace animation
} // namespace p2d