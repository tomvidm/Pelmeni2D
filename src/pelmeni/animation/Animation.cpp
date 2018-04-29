#include "animation/Animation.hpp"
#include <iostream>
namespace p2d { namespace animation {
    Animation::Animation()
    : keyframeInterpolationMethod(KeyframeInterpolationMethod::Linear) {
        ;
    }

    Animation::Animation(const std::vector<Keyframe>& keyframeList, const KeyframeInterpolationMethod interpolationMethod)
    : keyframeInterpolationMethod(interpolationMethod),
      currentKeyframeIndex(0),
      timeElapsedCurrentKeyframe(sf::seconds(0.f)),
      keyframes(keyframeList) {
          linearInterpolator.setEndpoints(keyframes[0].frame, keyframes[1].frame);
    }

    Frame Animation::getCurrentFrame() const {
        const float fractionalTimeElapsed = 
                    timeElapsedCurrentKeyframe.asSeconds() / 
                    getCurrentKeyframe().duration.asSeconds();
        return linearInterpolator.getInterpolated(fractionalTimeElapsed);
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

    void Animation::setInterpolationMethod(const KeyframeInterpolationMethod interpolationMethod) {
        keyframeInterpolationMethod = interpolationMethod;
    }

    void Animation::update(const sf::Time dt) {
        timeElapsedCurrentKeyframe += dt;
        auto& currentKeyframe = getCurrentKeyframe();
        if (timeElapsedCurrentKeyframe >= currentKeyframe.duration) {
            ++currentKeyframeIndex;
            timeElapsedCurrentKeyframe -= currentKeyframe.duration;
            linearInterpolator.setEndpoints(keyframes[currentKeyframeIndex].frame,
                                      keyframes[currentKeyframeIndex + 1].frame);
        }
    }

    void Animation::reset() {
        timeElapsedCurrentKeyframe = sf::seconds(0.f);
        currentKeyframeIndex = 0;
    }

    void Animation::setKeyframes(const std::vector<Keyframe>& keyframeList) {
        keyframes = keyframeList;
        reset();
    }
} // namespace animation
} // namespace p2d