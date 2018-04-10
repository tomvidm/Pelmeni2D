#pragma once

#include "SFML/Graphics.hpp"

#include "system/Transformable3.hpp"

namespace p2d { namespace graphics {
    class Axes : public system::Transformable3, public sf::Drawable {
    public:
        Axes();
        void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vertex vertices[6];
    }; // class Axes
}
}