#pragma once

#include "graphics/particles/ParticleSystem.hpp"

namespace p2d { namespace graphics { namespace particles {
    void ParticleSystem::updateVertices() {
        vertices.resize(4 * particles.size());
        for (size_t i = 0; i < particles.size(); i++) {
            sf::Vertex* quad = &vertices[4*i];
            // Set the position of the vertices of the quad
            // Use sf::Transform and Particle class' inheritance of sf::Transformable
            // to simplify this
        }
    }
} // namespace particles
} // namespace graphics
} // namespace p2d