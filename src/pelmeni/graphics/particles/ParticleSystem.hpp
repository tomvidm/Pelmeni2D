#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/particles/Particle2D.hpp"

namespace p2d { namespace graphics {
    class ParticleSystem : public sf::Transformable {
    private:
        std::vector<Particle2D> particles;
    };
} // namespace graphics
} // namespace p2d