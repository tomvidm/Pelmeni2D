#include "AnimationState.hpp"

#include <iostream>

namespace p2d { namespace graphics {
    void AnimationState::setFrameSequence(FrameSequence& fSequence) {
        frameSequencePtr = &fSequence;
        resetAnimation();
    } // setAnimation

    void AnimationState::resetAnimation() {
        currentFrameIndex = 0;
        frameTime = sf::milliseconds(0);
    } // resetAnimation

    bool AnimationState::update(const sf::Time& time) {
        //std::cout << getCurrentFrameDuration().asSeconds() << std::endl;
        frameTime += time;
        if (frameTime > getCurrentFrameDuration()) {
            currentFrameIndex += frameTime / getCurrentFrameDuration();
            currentFrameIndex %= frameSequencePtr->getNumFrames();
            frameTime -= getCurrentFrameDuration();
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
        return (*frameSequencePtr)[currentFrameIndex];
    } // getCurrentFrame
}
}