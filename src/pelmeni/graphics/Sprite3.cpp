#include "graphics/Sprite3.hpp"

namespace p2d { namespace graphics {
    Sprite3::Sprite3() {
        updateVertices();
    }
    void Sprite3::updateVertices() {
        const math::Vector2f spritePos = positionProjectedToXY();
        const float sin = sinf(yaw);
        const float cos = cosf(yaw);
        vertices[0].position = spritePos;
        vertices[1].position = spritePos + 32.f * math::Vector2f(cos, sin);
        vertices[2].position = spritePos + 32.f * math::Vector2f(sin, -cos);
        vertices[3].position = spritePos + 32.f * math::Vector2f(cos + sin, sin - cos);
    }

    void Sprite3::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices, 4, sf::PrimitiveType::TrianglesStrip, states);
    }
} // namespace graphics
} // namespace p2d