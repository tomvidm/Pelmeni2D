#include "graphics/Axes.hpp"

namespace p2d { namespace graphics {
    Axes::Axes() {
        vertices[0].color = sf::Color::Red;
        vertices[1].color = sf::Color::Red;
        vertices[2].color = sf::Color::Green;
        vertices[3].color = sf::Color::Green;
        vertices[4].color = sf::Color::Blue;
        vertices[5].color = sf::Color::Blue;
    }

    void Axes::update() {
        static const math::Vector3f localX(64.f, 0.f, 0.f);
        static const math::Vector3f localY(0.f, 64.f, 0.f);
        static const math::Vector3f localZ(0.f, 0.f, 64.f);

        vertices[0].position = math::projectToXY(getPosition());
        vertices[1].position = math::projectToXY(getTransform3().transformVector(localX));
        vertices[2].position = math::projectToXY(getPosition());
        vertices[3].position = math::projectToXY(getTransform3().transformVector(localY));
        vertices[4].position = math::projectToXY(getPosition());
        vertices[5].position = math::projectToXY(getTransform3().transformVector(localZ));
    }

    void Axes::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices, 6, sf::PrimitiveType::Lines, states);
    }
}
}