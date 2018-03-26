#include "AnimationState.hpp"

#include <iostream>

namespace p2d { namespace graphics {
    void AnimationState::setFrameSequence(FrameSequencePtr fSequencePtr) {
        frameSequencePtr = fSequencePtr;
    } // setAnimation

    void AnimationState::resetAnimation() {
        currentFrameIndex = 0;
        frameTimer.restart();
    } // resetAnimation

    bool AnimationState::update() {
        //std::cout << getCurrentFrameDuration().asSeconds() << std::endl;
        if (frameTimer.getElapsedTime() > getCurrentFrameDuration()) {
            currentFrameIndex += 1;
            currentFrameIndex %= frameSequencePtr->getNumFrames();
            frameTimer.restart();
            return true;
        } else { 
            return false;
        } // if else
    } // update

    sf::Rect<int>& AnimationState::getCurrentFrameRect() const {
        return getCurrentFrame().frameRect;
    } // getCurrentFrameRect

    sf::Time& AnimationState::getCurrentFrameDuration() const {
        return getCurrentFrame().duration;
    } // getCurrentFrameRect

    Frame& AnimationState::getCurrentFrame() const {
        return (*frameSequencePtr)[currentFrameIndex];
    } // getCurrentFrame
}
}