#include "AnimationState.hpp"

namespace p2d { namespace graphics {
    void AnimationState::setFrameSequence(FrameSequence& fSequence) {
        frameSequence = &fSequence;
    } // setAnimation

    void AnimationState::resetAnimation() {
        currentFrameIndex = 0;
        frameTimer.restart();
    } // resetAnimation

    bool AnimationState::update() {
        if (frameTimer.getElapsedTime() > getCurrentFrameDuration()) {
            ++currentFrameIndex;
            frameTimer.restart();
            return true;
        } else { 
            return false;
        } // if else
    } // update

    sf::Rect<float>& AnimationState::getCurrentFrameRect() const {
        return getCurrentFrame().frameRect;
    } // getCurrentFrameRect

    sf::Time& AnimationState::getCurrentFrameDuration() const {
        return getCurrentFrame().duration;
    } // getCurrentFrameRect

    Frame& AnimationState::getCurrentFrame() const {
        return (*frameSequence)[currentFrameIndex];
    } // getCurrentFrame
}
}