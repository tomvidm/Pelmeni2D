#include "animation/Animation.hpp"

namespace p2d { namespace animation {
    Animation::Animation() {
        ;
    }

    void Animation::setAnimationPath(const math::BezierCurve& curve) {
        data.path = curve;
    }

    void Animation::setAnimationDuraction(const sf::Time time) {
        data.duration = time;
    }

    math::Vector2f Animation::getPathStart() const {
        return data.path.getStart();
    }

    math::Vector2f Animation::getPathEnd() const {
        return data.path.getEnd();
    }
} // namespace animation
} // namespace p2d