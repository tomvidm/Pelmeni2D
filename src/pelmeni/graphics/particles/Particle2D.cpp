#include "graphics/particles/Particle2D.hpp"

namespace p2d { namespace graphics {
    Particle2D::Particle2D(const math::Vector2f& initialPosition,
                           const float& initialMass, 
                           const float& initialMoment,
                           const float& initialAngularVelocity,
                           const math::Vector2f& initialVelocity)
    : Body2D(
        initialPosition,
        initialMass,
        initialMoment,
        initialAngularVelocity,
        initialVelocity) {
            ;
    }

    void Particle2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= math::toSfmlTransform(getLocalTransform());
        target.draw(vertices, 4, sf::PrimitiveType::Quads, states);
    }
} // namespace graphics
} // namespace p2d