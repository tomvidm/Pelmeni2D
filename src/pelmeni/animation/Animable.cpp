#include "animation/Animable.hpp"

namespace p2d { namespace animation {
    void Animable::updateAnimation(const sf::Time dt) {
        if (animationIsRunning) {
            animation.update(dt);
            const auto& currentAnimationFrame = animation.getCurrentFrame();
            setPosition(currentAnimationFrame.position);
            setScale(currentAnimationFrame.scale);
            setOrigin(currentAnimationFrame.origin);
            setRotation(currentAnimationFrame.angle);
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
} // namespace animation
} // namespace p2d