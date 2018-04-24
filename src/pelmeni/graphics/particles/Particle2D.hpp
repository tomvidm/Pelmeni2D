#pragma once

#include "SFML/Graphics.hpp"

#include "physics/Body2D.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace graphics {
    class Particle2D 
    : public physics::Body2D,
      public sf::Drawable {
    public:
        Particle2D(const math::Vector2f& initialPosition,
                 const float& initialMass, 
                 const float& initialMoment,
                 const float& initialAngularVelocity,
                 const math::Vector2f& initialVelocity);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vertex vertices[4];
    };
} // namespace graphics
} // namespace p2d