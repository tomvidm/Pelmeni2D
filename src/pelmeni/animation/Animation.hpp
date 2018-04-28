#pragma once

#include "SFML/System/Time.hpp"

#include "math/BezierCurve.hpp"

namespace p2d { namespace animation {
    struct Animation {
        Animation() { ; }
        std::unique_ptr<math::BezierCurve> path;
        sf::Time timeDuration;
        sf::Time timeElapsed;

        inline float getNormalizedTimeElapsed() const { return timeElapsed.asSeconds() / timeDuration.asSeconds(); }
    }; // struct Animation
} // namespace animation
} // namespace p2d