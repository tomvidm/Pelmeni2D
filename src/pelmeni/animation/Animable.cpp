#include "animation/Animable.hpp"

namespace p2d { namespace animation {
    void Animable::update(const sf::Time dt) {
        if (!animationRunning) return;
        if (anim->timeElapsed.asSeconds() == 0.f) {
            setPosition(anim->path->getStart());
        } else {
            anim->timeElapsed += dt;
            if (dt >= anim->timeDuration) {
                setPosition(anim->path->getEnd());
                animationRunning = false;
            } else {
                const float percentComplete = anim->getNormalizedTimeElapsed();
                setPosition(anim->path->generatePointOnCurve(percentComplete));
            }
        }
    }

    void Animable::setAnimation(Animation* animation) {
        anim = animation;
        animationRunning = true;
    }
} // namespace animation
} // namespace p2d