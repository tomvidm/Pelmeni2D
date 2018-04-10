#include "graphics/Sprite3.hpp"

namespace p2d { namespace graphics {
    Sprite3::Sprite3() {
        updateVertices();
    }
    void Sprite3::updateVertices() {
        const math::Vector2f spritePos = math::projectToXY(position);
        const float sine = sinf(yaw);
        const float cosine = cosf(yaw);
        const float sxs = scale.x * sine;
        const float sxc = scale.x * cosine;
        const float sys = scale.y * sine;
        const float syc = scale.y * cosine;
        const float tx = -origin.x * sxc - origin.y * sys + spritePos.x;
        const float ty = origin.x * sxs - origin.y * syc + spritePos.y;

        const math::Transform transform(
            sxc, sys, tx,
            -sxs, syc, ty,
            0.f, 0.f, 1.f
        );

        vertices[0].position = spritePos + transform.transformPoint(0.f, 0.f);
        vertices[1].position = spritePos + transform.transformPoint(32.f, 0.f);
        vertices[2].position = spritePos + transform.transformPoint(0.f, 32.f);
        vertices[3].position = spritePos + transform.transformPoint(32.f, 32.f);
    }

    void Sprite3::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices, 4, sf::PrimitiveType::TrianglesStrip, states);
    }
} // namespace graphics
} // namespace p2d