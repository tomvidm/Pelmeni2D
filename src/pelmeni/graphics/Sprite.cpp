#include <cstdio>

#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::setSpritePack(SpritePack::shared spritePackArg) {
        spritePack = spritePackArg;
        setTexture(spritePack->texture.getTexture());
    }
} // namespace graphics
} // namespace p2d