#pragma once

#include <math.h>
#include <tuple>
#include <array>
#include <vector>

#include "SFML/Graphics.hpp"

#include "math/Radian.hpp"
#include "physics/Body2D.hpp"
#include "physics/Spring2D.hpp"

constexpr size_t numVertices = 16;
constexpr float angle(const size_t N) {
    return 2*M_PI/static_cast<float>(N);
}
constexpr float edgeLength(const float radius) {
    return radius * cosf(angle(numVertices)/2.f);
}

namespace p2d { namespace experimental {
    class Gish : public sf::Drawable {
    public:
        Gish();

        void update(const float& dt);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        const physics::Spring2D edgeSpring = physics::Spring2D(1.f, 0.5f, edgeLength(100.f));
        const physics::Spring2D centroidSpring = physics::Spring2D(1.f, 1.5f, 100.f);
        physics::Body2D centroid;
        std::array<physics::Body2D, numVertices + 1> points;

        std::vector<std::tuple<size_t, size_t>> edges; 
        std::vector<std::tuple<size_t, size_t>> radials; 

        sf::VertexArray vertices;
        
    }; // class Gish
} // namespace experimental
} // namespace p2d