#include "animation/Animation.hpp"
#include <iostream>
namespace p2d { namespace animation {
    Animation::Animation(const std::vector<Keyframe>& keyframeList)
    : currentKeyframeIndex(0),
      timeElapsedCurrentKeyframe(sf::seconds(0.f)),
      keyframes(keyframeList) {
          interpolator.setEndpoints(keyframes[0].frame, keyframes[1].frame);
    }

    Frame Animation::getCurrentFrame() const {
        const float fractionalTimeElapsed = 
                    timeElapsedCurrentKeyframe.asSeconds() / 
                    getCurrentKeyframe().duration.asSeconds();
        return interpolator.getInterpolated(fractionalTimeElapsed);
    };

    Keyframe& Animation::getCurrentKeyframe() {
        return keyframes[currentKeyframeIndex];
    }

    const Keyframe& Animation::getCurrentKeyframe() const {
        return keyframes[currentKeyframeIndex];
    }

    const size_t Animation::getCurrentKeyframeIndex() const {
        return currentKeyframeIndex;
    }

    void Animation::update(const sf::Time dt) {
        timeElapsedCurrentKeyframe += dt;
        auto& currentKeyframe = getCurrentKeyframe();
        if (timeElapsedCurrentKeyframe >= currentKeyframe.duration) {
            timeElapsedCurrentKeyframe -= currentKeyframe.duration;
            ++currentKeyframeIndex;
            interpolator.setEndpoints(keyframes[currentKeyframeIndex].frame,
                                      keyframes[currentKeyframeIndex + 1].frame);
        }
    }
} // namespace animation
} // namespace p2d