#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/Tilemap.hpp"
#include "math/graph/TilemapGraph.hpp"
#include "input/InputListener.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace experimental {
    class TilemapWIP
    : public math::TilemapGraph,
      public graphics::Tilemap,
      public input::InputListener
      /* public system::Transformable2, */
      /* public sf::Drawable */ {
    public:
        virtual void onEvent(const input::InputEvent& event);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    }; // class Tilemap
}
}