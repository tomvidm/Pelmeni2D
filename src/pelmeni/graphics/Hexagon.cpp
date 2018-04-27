#include "graphics/Hexagon.hpp"

namespace p2d { namespace graphics {
    void Hexagon::initializeVertices() {
        auto vectors = math::RegularHexagon::getVectors(1.f);
    }

    void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices, 8, sf::PrimitiveType::Quads, states);
    }
}
}