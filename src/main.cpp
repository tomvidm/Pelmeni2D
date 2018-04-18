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
            elevation[r][c] = 255.f * std::min(randf(), std::min(randf(), randf()));
        }
    }

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            const size_t i = r * cols + c;
            if (r < rows - 1) {
                const float weightTo = std::max(0.f, elevation[r + 1][c] - elevation[r][c]);
                const float weightFrom = std::max(0.f, elevation[r][c] - elevation[r + 1][c]);
                const size_t i_down = (r + 1) * cols + c;
                graph.connectTo(i, i_down, weightTo);
                graph.connectTo(i_down, i, weightFrom);
            }
            if (c < cols - 1) {
                const float weightTo = std::max(0.f, elevation[r][c + 1] - elevation[r][c]);
                const float weightFrom = std::max(0.f, elevation[r][c] - elevation[r][c + 1]);
                const size_t i_right = r * cols + c + 1;
                graph.connectTo(i, i_right, weightTo);
                graph.connectTo(i_right, i, weightFrom);
            }

        }
    }

    graphics::Tilemap tmap;
    tmap.setTilemapSize(rows, cols);
    tmap.setTileSize(math::Vector2f(4.f, 4.f));
    tmap.buildTilemap();
    tmap.setRenderGrid(false);


    sf::RenderWindow window(sf::VideoMode(1366, 768), "main.cpp");
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
            const size_t sourceNode = mi;


            math::CostCounter precalculatedPathCosts = math::precalculatedGraphCosts(graph, sourceNode);

            float maxCost = 0.f;
            for (auto& step : precalculatedPathCosts) {
                maxCost = std::max(maxCost, step.costToThis);
            }
            float factor = 255.f / maxCost;
            printf("%zu   ", sourceNode);
            printf("max cost = %f, factor = %f\n", maxCost, factor);
            for (auto& step : precalculatedPathCosts) {
                const size_t i = step.thisNode;
                const size_t col = i % cols;
                const size_t row = (i - col) / cols;
                const float cost = step.costToThis;
                const float costNormalized = cost * factor;
                const uint8_t costInteger = static_cast<uint8_t>(costNormalized);
                tmap.setQuadColor(row, col, sf::Color(costInteger, costInteger, costInteger));
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