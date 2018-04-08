#pragma once

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics { namespace particles {
    class ParticleSystem : public sf::Transformable {
    public:
        void updateVertices();
    private:
        std::vector<Particle> particles;
        sf::VertexArray vertices;
    };
} // namespace particles
} // namespace graphics
} // namespace p2d