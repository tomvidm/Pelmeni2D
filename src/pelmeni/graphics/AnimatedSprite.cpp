#include <cstdio>

#include "graphics/AnimatedSprite.hpp"

namespace p2d { namespace graphics {
    AnimatedSprite::AnimatedSprite() {
        ;
    }

    AnimatedSprite::AnimatedSprite(const AnimatedSprite& other) 
    : isDrawable(other.isDrawable),
      _animationState(other._animationState),
      _spritePack(other._spritePack) {
          ;
    }

    AnimatedSprite AnimatedSprite::operator = (const AnimatedSprite& other) {
        isDrawable = other.isDrawable;
        _animationState = other._animationState;
        _spritePack = other._spritePack;
        return *this;
    }

    void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        if (isDrawable) {
            states.transform *= math::toSfmlTransform(getLocalTransform());
            states.texture = _texturePtr;
            target.draw(_vertices, 4, sf::PrimitiveType::Quads, states);
        }
    } // draw

    void AnimatedSprite::setSpritePack(const SpritePack::shared spritePack) {
        _spritePack = spritePack;
        _texturePtr = &(_spritePack->texture.getTexture());
        isDrawable = true;
    } // setSpritePack

    void AnimatedSprite::setSpriteAnimation(const FrameSequence::alias& animationAlias) {
        _animationState.setFrameSequence(_spritePack->getFrameSequence(animationAlias));
    }

    void AnimatedSprite::update(const sf::Time& dt) {
        updateAnimation(dt);
        if (isDrawable && _animationState.update(dt)) {
            setTextureRect(_animationState.getCurrentFrameRect());
        }
    }
} // namespace graphics
} // namespace p2d