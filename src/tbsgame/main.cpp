#include <cstdio>

#include "graphics/Tilemap.hpp"

#include "system/Scene.hpp"
#include "input/Mouse.hpp"
#include "input/InputManager.hpp"

int main() {
    using namespace p2d;
    printf("Running tbsgame...\n");

    system::Scene mainScene("scenes/tbsgame.json");
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
            if (event.type == sf::Event::MouseMoved) {
                tilemap.setQuadColor(currentMouseoverTile, sf::Color(128, 128, 128));
                currentMouseoverTile = tilemap.vectorToTileCoordinate(input::getMousePosition(window));
                tilemap.setQuadColor(currentMouseoverTile, sf::Color(255, 128, 128));
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                tilemap.setQuadColor(currentSelectedTile, sf::Color(128, 128, 128));
                currentSelectedTile = tilemap.vectorToTileCoordinate(input::getMousePosition(window));
            }
        }
        tilemap.setQuadColor(currentSelectedTile, sf::Color(255, 64, 64));
        mainScene.updateEntities(dt);
        window.clear(sf::Color::White);
        mainScene.renderScene(window);
        window.draw(tilemap);
        window.display();
    }
    return 0;
}
