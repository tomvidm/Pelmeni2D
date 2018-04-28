#include <cstdio>

#include "graphics/SpriteBase.hpp"

namespace p2d { namespace graphics {
    SpriteBase::SpriteBase() {
        ;
    }

    SpriteBase::SpriteBase(const SpriteBase& other) 
    : _vertices(other._vertices),
      _texturePtr(other._texturePtr) {
          ;
    }

    void SpriteBase::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.texture = _texturePtr;
        target.draw(_vertices, 4, sf::PrimitiveType::Quads, states);
    } // draw

    void SpriteBase::setTextureRect(const sf::Rect<float>& rect) {
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

    void SpriteBase::setTexture(sf::Texture& texture) {
        _texturePtr = &texture;
    }
} // namespace graphics
} // namespace p2d