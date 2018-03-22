#pragma once

#include "SFML/Graphics.hpp"

#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
    class AnimationState {
    public:
        AnimationState() : currentFrameIndex(0), frameSequence(nullptr) {}
        void setAnimation(const FrameSequence& fSequence);
        void resetAnimation();

        void update();
        sf::Rect<float>& getRect() const;
    private:
        size_t currentFrameIndex;
        sf::Clock frameTimer;
        FrameSequence* frameSequence;
    }; // class AnimationState
} // namespace graphics
} // namespace p2d