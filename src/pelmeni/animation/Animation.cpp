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
        if (keyframeInterpolationMethod == KeyframeInterpolationMethod::Linear) {
            return linearInterpolator.getInterpolated(fractionalTimeElapsed);
        } else if (keyframeInterpolationMethod == KeyframeInterpolationMethod::CatmullRom) {
            return catmullRomInterpolator.getInterpolated(fractionalTimeElapsed);
        }
        
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
            timeElapsedCurrentKeyframe -= currentKeyframe.duration;
            ++currentKeyframeIndex;
            if (keyframeInterpolationMethod == KeyframeInterpolationMethod::Linear) {
                linearInterpolator.setEndpoints(keyframes[currentKeyframeIndex].frame,
                                                keyframes[currentKeyframeIndex + 1].frame);
            } else if (keyframeInterpolationMethod == KeyframeInterpolationMethod::CatmullRom) {
                std::vector<Frame> frames = {
                    keyframes[currentKeyframeIndex].frame,
                    keyframes[currentKeyframeIndex + 1].frame,
                    keyframes[currentKeyframeIndex + 2].frame,
                    keyframes[currentKeyframeIndex + 3].frame
                };
                catmullRomInterpolator.setControlPoints(frames, 0);
            }
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