#pragma once

#include "SFML/Graphics.hpp"

#include "system/Transformable3.hpp"

namespace p2d { namespace graphics {
    class Sprite3 : public system::Transformable3, public sf::Drawable {
    public:
        Sprite3();
        void updateVertices();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::Vertex vertices[4];
    }; // class Sprite3
} // namespace graphics
} // namespace p2d