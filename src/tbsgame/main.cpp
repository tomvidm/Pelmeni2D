#include <cstdio>

#include "graphics/Tilemap.hpp"

#include "system/Scene.hpp"
#include "input/Mouse.hpp"
#include "input/InputManager.hpp"
#include "graphics/Tilemap.hpp"

struct Object {
    p2d::graphics::TileCoordinate tile;
};

int main() {
    using namespace p2d;
    printf("Running tbsgame...\n");

    graphics::TileCoordinate currentMouseoverTile{0, 0};
    graphics::TileCoordinate currentSelectedTile{0, 0};
    graphics::Tilemap tilemap;

    tilemap.setTileSize(sf::Vector2f(32.f, 32.f));
    tilemap.setTilemapSize(32, 32);
    tilemap.buildTilemap();

    sf::RenderWindow window(sf::VideoMode(800, 600), "TBSGame");
    sf::Time dt;
    sf::Clock clk;
    while (window.isOpen()) {
        dt = clk.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}
