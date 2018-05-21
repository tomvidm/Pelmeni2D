#include <cstdio>

#include "graphics/Tilemap.hpp"

#include "system/Scene.hpp"
#include "input/Mouse.hpp"
#include "input/InputManager.hpp"
#include "graphics/Tilemap.hpp"
#include "math/graph/TilemapGraph.hpp"
#include <iostream>
struct Object {
    p2d::graphics::TileCoordinate currentTile;
    p2d::graphics::TileCoordinate newTile;
};

int main() {
    using namespace p2d;
    printf("Running tbsgame...\n");

    size_t numrows = 16;
    size_t numcols = 16;

    graphics::TileCoordinate currentMouseoverTile{0, 0};
    graphics::TileCoordinate currentSelectedTile{0, 0};
    graphics::Tilemap tilemap;
    math::TilemapGraph graph;

    sf::Color defaultColor = sf::Color(128, 128, 128);

    math::Heightmap hmap = math::buildUniformHeightmap(numrows, numcols);
    graph.buildGraphFromHeightmap(hmap);

    tilemap.setTileSize(sf::Vector2f(32.f, 32.f));
    tilemap.setTilemapSize(numrows, numcols);
    tilemap.buildTilemap();

    Object obj{{8, 8}, {8, 8}};
    math::CostCounter objCosts = math::precalculatedGraphCosts(graph, graph.getNode(obj.currentTile));
    math::Path shortestPathToMouseover = math::shortestPath_Dijkstra(graph.getNode(obj.currentTile), graph.getNode(currentMouseoverTile), objCosts);
    bool objectHasUpdatedPosition = true;

    for (size_t r = 0; r < numrows; r++) {
        for (size_t c = 0; c < numcols; c++) {
            const sf::Color col = sf::Color(
                64 + hmap.data[r][c],
                64 + hmap.data[r][c],
                64 + hmap.data[r][c]
            );
            printf("%f\n", hmap.data[r][c]);
            tilemap.setQuadColor(r, c, col);
        }
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "TBSGame");
    sf::Time dt;
    sf::Clock clk;
    while (window.isOpen()) {
        dt = clk.restart();
        sf::Event event;    
        if (objectHasUpdatedPosition) {
            objCosts = math::precalculatedGraphCosts(graph, graph.getNode(obj.currentTile));
            objectHasUpdatedPosition = false;
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        tilemap.setQuadColor(obj.currentTile, defaultColor);
        tilemap.setQuadColor(obj.newTile, sf::Color::Red);

        window.clear(sf::Color::White);
        window.draw(tilemap);
        window.display();
    }
    return 0;
}
