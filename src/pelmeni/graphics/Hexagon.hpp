#pragma once

#include "SFML/Graphics.hpp"

#include "math/geometry/Hexagon.hpp"

namespace p2d { namespace graphics {
    class Hexagon
    : public sf::Drawable {
    public:
        void initializeVertices();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vertex vertices[8];
    }; // class Hexgrid
}
}