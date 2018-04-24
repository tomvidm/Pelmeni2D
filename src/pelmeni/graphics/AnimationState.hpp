#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;
    class AnimationState {
    public:
        AnimationState() : currentFrameIndex(0), frameSequencePtr(nullptr) {}
        void setFrameSequence(FrameSequence& fSequence);
        void resetAnimation();

        bool update(const sf::Time& time);
        Frame& getCurrentFrame() const;
        sf::Rect<float>& getCurrentFrameRect() const;
        sf::Time& getCurrentFrameDuration() const;
    private:
        size_t currentFrameIndex;
        sf::Time frameTime;
        FrameSequence* frameSequencePtr;
    }; // class AnimationState
} // namespace graphics
} // namespace p2d