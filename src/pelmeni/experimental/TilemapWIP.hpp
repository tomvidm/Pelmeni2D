#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/Tilemap.hpp"
#include "math/graph/TilemapGraph.hpp"
#include "input/InputListener.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace experimental {
    std::vector<graphics::TileCoordinate> pathToTiles(const math::Path& path, const size_t rows, const size_t cols);

    class TilemapWIP
    : public input::InputListener,
      public math::TilemapGraph,
      public graphics::Tilemap
      /* public system::Transformable2, */
      /* public sf::Drawable */ {
    public:
        TilemapWIP(const size_t rows, const size_t cols);   

        virtual void onEvent(const input::InputEvent& event);
        virtual void onMouseButtonEvent(const input::InputEvent& event);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

        void assignHeightmapColors();
        void update();
    private:
        math::Heightmap hmap;
        graphics::TileCoordinate start;
        graphics::TileCoordinate end;
        size_t startNode = 0;
        size_t endNode = 1;
    }; // class Tilemap
}
}