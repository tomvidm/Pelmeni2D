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

    math::Graph graph;
    graph.addNodes(rows * cols);

    float elevation[rows][cols];
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            elevation[r][c] = 255.f * randf();
        }
    }

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            const size_t i = r * cols + c;
            if (r < rows - 1) {
                const float weight = abs(elevation[r][c] - elevation[r + 1][c]);
                const size_t i_down = (r + 1) * cols + c;
                graph.connect(i, i_down, weight);
            }
            if (c < cols - 1) {
                const float weight = abs(elevation[r][c] - elevation[r][c + 1]);
                const size_t i_right = r * cols + c + 1;
                graph.connect(i, i_right, weight);
            }
            if (c < cols - 1 && r < rows - 1) {
                const float weight_diag0 = abs(elevation[r][c] - elevation[r + 1][c + 1]);
                const float weight_diag1 = abs(elevation[r + 1][c] - elevation[r][c + 1]);
                const size_t i_diag0 = (r + 1) * cols + c + 1;
                const size_t i_diag1_a = (r + 1) * cols + c;
                const size_t i_diag1_b = r * cols + c + 1;
                graph.connect(i, i_diag0, weight_diag0);
                graph.connect(i_diag1_a, i_diag1_b, weight_diag1);
            }
        }
    }

    graphics::Tilemap tmap;
    tmap.setTilemapSize(rows, cols);
    tmap.setTileSize(math::Vector2f(4.f, 4.f));
    tmap.buildTilemap();
    tmap.setRenderGrid(false);


    sf::RenderWindow window(sf::VideoMode(800, 600), "main.cpp");
    sf::Event event;

    sf::Clock timer;
    while (window.isOpen()) {
        if (timer.getElapsedTime() > sf::milliseconds(10.f)) {
            timer.restart();
            const math::Vector2i mpos_pixel = sf::Mouse::getPosition(window);
            const math::Vector2f mpos_screen = window.mapPixelToCoords(mpos_pixel);
            const graphics::TileCoordinate tileCoords = tmap.vectorToTileCoordinate(mpos_screen);
            const size_t mrow = tileCoords.row;
            const size_t mcol = tileCoords.col;
            const size_t mi = mrow * cols + mcol;

            const size_t startNode = 0;
            const size_t endNode = mi;

            math::Path shortestPath = math::shortestPath_Dijkstra(graph, startNode, endNode);

            for (size_t r = 0; r < rows; r++) {
                for (size_t c = 0; c < cols; c++) {
                    const float tileElevation = elevation[r][c];
                    tmap.setQuadColor(r, c, sf::Color(tileElevation, tileElevation, tileElevation));
                }
            }
            //printf("Shortest path\n");
            for (auto& step : shortestPath) {
                const size_t i = step.thisNode;
                const size_t col = i % cols;
                const size_t row = (i - col) / cols;
                //printf("%zu - (%zu, %zu)\n", i, row, col);
                if (step.costToThis < 5.f) {
                    tmap.setQuadColor(row, col, sf::Color::Green);
                } else {
                    tmap.setQuadColor(row, col, sf::Color::Red);
                }
            }
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(tmap);
        window.display();

    }

    return 0;
} // Main function