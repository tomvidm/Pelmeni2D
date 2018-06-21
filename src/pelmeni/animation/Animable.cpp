#include "animation/Animable.hpp"

namespace p2d { namespace animation {
    void Animable::updateAnimation(const sf::Time dt) {
        if (animationIsRunning) {
            animation.update(dt);
            const auto& currentAnimationFrame = animation.getCurrentFrame();
            applyFrame(currentAnimationFrame);
        }
    }

    void Animable::setAnimation(const Animation& anim) {
        animation = anim;
    }

    void Animable::stopAnimation() {
        animationIsRunning = false;
    }
    void Animable::startAnimation() {
        animationIsRunning = true;
    }

    void Animable::applyFrame(const Frame& frame) {
        setPosition(frame.position);
        setScale(frame.scale);
        setOrigin(frame.origin);
        setRotation(frame.angle);
    }
} // namespace animation
} // namespace p2d