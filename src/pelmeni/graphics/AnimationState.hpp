#pragma once

#include "SFML/Graphics.hpp"

#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
    class AnimationState {
    public:
        AnimationState() : currentFrameIndex(0), frameSequence(nullptr) {}
        void setFrameSequence(FrameSequence& fSequence);
        void resetAnimation();

        bool update();
        Frame& getCurrentFrame() const;
        sf::Rect<float>& getCurrentFrameRect() const;
        sf::Time& getCurrentFrameDuration() const;
    private:
        size_t currentFrameIndex;
        sf::Clock frameTimer;
        FrameSequence* frameSequence;
    }; // class AnimationState
} // namespace graphics
} // namespace p2d