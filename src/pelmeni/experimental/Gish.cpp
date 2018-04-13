#include "experimental/Gish.hpp"

namespace p2d { namespace experimental {
    Gish::Gish() {
        vertices.resize(4*numVertices);
        vertices.setPrimitiveType(sf::PrimitiveType::Lines);

        math::Radian radsPerVertex = math::fromAngle(360.f / static_cast<float>(numVertices));
        for (size_t i = 0; i < numVertices; i++) {
            const float radians = static_cast<float>(i) * radsPerVertex.toRadians();
            const float xpos = 128.f*cosf(radians) + 300.f;
            const float ypos = 128.f*sinf(radians) + 300.f;
            edges.push_back(std::make_tuple(i, (i + 1) % numVertices));
            radials.push_back(std::make_tuple(i, numVertices));
            points[i].setPosition(math::Vector2f(xpos, ypos));
        }
    }

    void Gish::update(const float& dt) {
        for (size_t i = 0; i < edges.size(); i++) {
            const size_t a = std::get<0>(edges[i]);
            const size_t b = std::get<1>(edges[i]);
            physics::Body2D& b0 = points[a];
            physics::Body2D& b1 = points[b];
            physics::Force2 force = edgeSpring.calculateForce(b0, b1);
            b1.applyForce(force, dt);
            b0.applyForce(-force, dt);
        }

        for (size_t i = 0; i < radials.size(); i++) {
            const size_t a = std::get<0>(radials[i]);
            const size_t b = std::get<1>(radials[i]);
            physics::Body2D& b0 = points[a];
            physics::Body2D& b1 = points[b];
            physics::Force2 force = centroidSpring.calculateForce(b0, b1);
            b1.applyForce(force, dt);
            b0.applyForce(-force, dt);
        }

        for (size_t i = 0; i < edges.size(); i++) {
            const size_t a = std::get<0>(edges[i]);
            const size_t b = std::get<1>(edges[i]);
            physics::Body2D& b0 = points[a];
            physics::Body2D& b1 = points[b];
            b0.update(dt);
            b1.update(dt);
            const math::Vector2f v0 = b0.getPosition();
            const math::Vector2f v1 = b1.getPosition();
            vertices[2*i].position = v0;
            vertices[2*i + 1].position = v1;
        }

        for (size_t i = 0; i < radials.size(); i++) {
            const size_t a = std::get<0>(radials[i]);
            const size_t b = std::get<1>(radials[i]);
            physics::Body2D& b0 = points[a];
            physics::Body2D& b1 = points[b];
            b0.update(dt);
            b1.update(dt);
            const math::Vector2f v0 = b0.getPosition();
            const math::Vector2f v1 = b1.getPosition();
            vertices[2*i + 2*numVertices].position = v0;
            vertices[2*i + 1 + 2*numVertices].position = v1;
        }
    }

    void Gish::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices);
    }
} // namespace experimental
} // namespace p2d
