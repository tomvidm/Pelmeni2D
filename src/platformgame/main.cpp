#include <cstdio>

#include "graphics/Tilemap.hpp"

#include "system/Scene.hpp"

int main() {
    using namespace p2d;
    printf("Running platformgame...\n");

    system::Scene scene("scenes/platformgame.json");

    sf::RenderWindow window(sf::VideoMode(800, 600), "PlatformGame");
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
