#pragma once

#include <cstdlib>
#include <vector>

#include "SFML/System/Time.hpp"

#include "animation/Keyframe.hpp"
#include "math/LinearInterpolation.hpp"
#include "math/CatmullRomInterpolator.hpp"

namespace p2d { namespace animation {
    enum class KeyframeInterpolationMethod {
        Linear,
        CatmullRom
    };  

    class Animation {
    public:
        Animation();
        Animation(const std::vector<Keyframe>& keyframeList, const KeyframeInterpolationMethod interpolationMethod = KeyframeInterpolationMethod::Linear);

        Frame getCurrentFrame() const;

        Keyframe& getCurrentKeyframe();
        const Keyframe& getCurrentKeyframe() const;
        const size_t getCurrentKeyframeIndex() const;

        void setInterpolationMethod(const KeyframeInterpolationMethod interpolationMethod);

        void update(const sf::Time dt);
        void reset();
        void setKeyframes(const std::vector<Keyframe>& keyframeList);
    private:
        KeyframeInterpolationMethod keyframeInterpolationMethod;
        size_t currentKeyframeIndex;
        sf::Time timeElapsedCurrentKeyframe;
        std::vector<Keyframe> keyframes;
        math::LinearInterpolation<Frame> linearInterpolator;
        math::CatmullRomInterpolator<Frame> catmullRomInterpolator;
    }; // class Animation
} // namespace animation
} // namespace p2d