#pragma once

#include <memory>

#include "math/BezierCurve.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace animation {
    class Animable
    : public system::Transformable2 {
    public:
        void update(const sf::Time dt);
    }; // class Animable
} // namespace animation
} // namespace p2d