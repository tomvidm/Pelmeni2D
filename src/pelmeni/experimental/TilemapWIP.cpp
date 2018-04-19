#include "experimental/TilemapWIP.hpp"

#include "math/graph/TilemapGraph.hpp"

namespace p2d { namespace experimental {
    std::vector<graphics::TileCoordinate> pathToTiles(const math::Path& path, const size_t rows, const size_t cols) {
        std::vector<graphics::TileCoordinate> tiles;
        for (auto& step : path) {
            const size_t col = step.thisNode % cols;
            const size_t row = (step.thisNode - col) / cols;
            tiles.push_back(graphics::TileCoordinate{
                row,
                col
            });
        }
        return tiles;
    }

    TilemapWIP::TilemapWIP(const size_t rows, const size_t cols) {
        hmap = math::buildRandomHeightmap(rows, cols);
        buildGraphFromHeightmap(hmap);
        setRenderGrid(false);
        setTileSize(math::Vector2f(4.f, 4.f));
        setTilemapSize(rows, cols);
        buildTilemap();
    }

    void TilemapWIP::onEvent(const input::InputEvent& event) {
        if (event.eventType == input::InputEventType::MOUSEBUTTON) {
            onMouseButtonEvent(event);
        } else if (event.eventType == input::InputEventType::MOUSEMOVE) {
            const math::Vector2i mpos_pixel = sf::Mouse::getPosition(*event.window);
            const math::Vector2f mpos_screen = event.window->mapPixelToCoords(mpos_pixel);
            const graphics::TileCoordinate tile = vectorToTileCoordinate(mpos_screen);
            end = tile;
            endNode = tile.row * numCols + tile.col;
        }
    }

    void TilemapWIP::onMouseButtonEvent(const input::InputEvent& event) {
        if (event.mouseButtonEvent.eventType == input::MouseButtonEventType::CLICK) {
            const math::Vector2i mpos_pixel = sf::Mouse::getPosition(*event.window);
            const math::Vector2f mpos_screen = event.window->mapPixelToCoords(mpos_pixel);
            const graphics::TileCoordinate tile = vectorToTileCoordinate(mpos_screen);
            if (event.mouseButtonEvent.button == input::MouseButton::LEFT) {
                start = tile;
                startNode = tile.row * numCols + tile.col;
            } else if (event.mouseButtonEvent.button == input::MouseButton::RIGHT) {
                end = tile;
                endNode = tile.row * numCols + tile.col;
            }
        }
    }

    void TilemapWIP::draw(sf::RenderTarget& target, sf::RenderStates states) {
        states.transform *= toSfmlTransform(getLocalTransform());
        states.texture = &tilemapTexture.getTexture();
        target.draw(mesh, states);
    }

    void TilemapWIP::assignHeightmapColors() {
        for (size_t r = 0; r < numRows; r++) {
            for (size_t c = 0; c < numCols; c++) {
                const float val = hmap.data[r][c];
                const sf::Color color = sf::Color(val, val, val);
                setQuadColor(r, c, color);
            }
        }
    }

    void TilemapWIP::update() {
        assignHeightmapColors();
        math::Path shortestPath = math::shortestPath_Dijkstra(*this, startNode, endNode);
        std::vector<graphics::TileCoordinate> tiles = pathToTiles(shortestPath, numRows, numCols);

        for (auto& tile : tiles) {
            setQuadColor(tile, sf::Color::Red + getQuadColor(tile.row, tile.col));
        }
    }
}
}