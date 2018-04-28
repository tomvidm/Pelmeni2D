#include "animation/Animable.hpp"

namespace p2d { namespace animation {
    void Animable::updateAnimation(const sf::Time dt) {
        animation.update(dt);
        const auto& currentAnimationFrame = animation.getCurrentFrame();
        setPosition(currentAnimationFrame.position);
        setScale(currentAnimationFrame.scale);
        setRotation(currentAnimationFrame.angle);
    }

    void Animable::setAnimation(const Animation& anim) {
        animation = anim;
    }
} // namespace animation
} // namespace p2d