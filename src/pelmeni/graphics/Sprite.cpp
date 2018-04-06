#include <cstdio>

#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::setSpritePack(SpritePack::shared spritePackArg) {
        spritePack = spritePackArg;
        setTexture(spritePack->texture.getTexture());
        setFrameSequence("default");
    }

    void Sprite::setFrameSequence(const FrameSequence::id& fSeqId) {
        animationState.setFrameSequence(spritePack->getFrameSequence(fSeqId));
    }

    void Sprite::update(const sf::Time& dt) {
        if (animationState.update(dt)) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    }
} // namespace graphics
} // namespace p2d