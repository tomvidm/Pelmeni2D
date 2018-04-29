#pragma once

#include <cstdlib>
#include <vector>

#include "SFML/System/Time.hpp"

#include "animation/Keyframe.hpp"
#include "math/LinearInterpolation.hpp"

namespace p2d { namespace animation {
    enum class KeyframeInterpolationMethod {
        Linear,
        CatmullRom
    };  

    class Animation {
    public:
        Animation();
        Animation(const std::vector<Keyframe>& keyframeList);

        Frame getCurrentFrame() const;

        Keyframe& getCurrentKeyframe();
        const Keyframe& getCurrentKeyframe() const;
        const size_t getCurrentKeyframeIndex() const;

        void update(const sf::Time dt);
        void reset();
        void setKeyframes(const std::vector<Keyframe>& keyframeList);
    private:
        size_t currentKeyframeIndex;
        sf::Time timeElapsedCurrentKeyframe;
        std::vector<Keyframe> keyframes;
        math::LinearInterpolation<Frame> interpolator;
    }; // class Animation
} // namespace animation
} // namespace p2d