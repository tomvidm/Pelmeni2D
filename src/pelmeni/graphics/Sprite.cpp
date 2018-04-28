#include <cstdio>

#include "graphics/Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        if (isDrawable) {
            states.transform *= math::toSfmlTransform(getLocalTransform());
            states.texture = _texturePtr;
            target.draw(_vertices, 4, sf::PrimitiveType::Quads, states);
        }
    } // draw

    void Sprite::setSpritePack(const SpritePack::shared spritePack) {
        _spritePack = spritePack;
        _texturePtr = &(_spritePack->texture.getTexture());
        isDrawable = true;
    } // setSpritePack

    void Sprite::setSpriteAnimation(const FrameSequence::alias& animationAlias) {
        _animationState.setFrameSequence(_spritePack->getFrameSequence(animationAlias));
    }

    void Sprite::update(const sf::Time& dt) {
        if (isDrawable && _animationState.update(dt)) {
            setTextureRect(_animationState.getCurrentFrameRect());
        }
    }

    void Sprite::setTextureRect(const sf::Rect<float>& rect) {
        const math::Vector2f topLeft(rect.left, rect.top);
        const math::Vector2f topRight(rect.left + rect.width, rect.top);
        const math::Vector2f bottomRight(rect.left + rect.width, rect.top + rect.height);
        const math::Vector2f bottomLeft(rect.left, rect.top + rect.height);
        const math::Vector2f size(rect.width, rect.height);
        _vertices[0].texCoords = topLeft;
        _vertices[1].texCoords = topRight;
        _vertices[2].texCoords = bottomRight;
        _vertices[3].texCoords = bottomLeft;
        _vertices[0].position = math::Vector2f();
        _vertices[1].position = math::projectToX(size);
        _vertices[2].position = size;
        _vertices[3].position = math::projectToY(size);
    }
} // namespace graphics
} // namespace p2d