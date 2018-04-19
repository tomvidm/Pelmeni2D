#include <iostream>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <tuple>


#include "SFML/Graphics.hpp"

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"

#include "graphics/Tilemap.hpp"
#include "math/graph/TilemapGraph.hpp"
#include "experimental/TilemapWIP.hpp"

float randf() {
    const float r = static_cast<float>(rand());
    const float r_max = static_cast<float>(RAND_MAX);
    return r / r_max;
}

int main() {
    using namespace p2d;
    const size_t rows = 128;
    const size_t cols = 128;

    srand(time(NULL));

    math::Heightmap heightmap{rows, cols};

    heightmap.data.resize(rows);
    for (size_t r = 0; r < rows; r++) {
        heightmap.data[r].resize(cols);
        for (size_t c = 0; c < cols; c++) {
            heightmap.data[r][c] = 255 * std::min(randf(), std::min(randf(), randf()));
        }
    }

    experimental::TilemapWIP tmap;
    tmap.buildGraphFromHeightmap(heightmap);
    tmap.setTilemapSize(rows, cols);
    tmap.setTileSize(math::Vector2f(8.f, 8.f));
    tmap.buildTilemap();
    tmap.setRenderGrid(false);


    sf::RenderWindow window(sf::VideoMode(1366, 768), "main.cpp");
    sf::Event event;

    sf::Clock timer;
    while (window.isOpen()) {
        if (timer.getElapsedTime() > sf::milliseconds(10.f)) {
            timer.restart();

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(tmap);
            window.display();
        }

    }

    return 0;
} // Main function