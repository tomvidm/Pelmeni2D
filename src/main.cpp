#include <iostream>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <tuple>
#include <array>


#include "SFML/Graphics.hpp"
#include "math/Vector2.hpp"
#include "graphics/Mesh2D.hpp"
#include "graphics/MeshData2D.hpp"
#include "math/ConvexPolygon.hpp"


int main() {
    using namespace p2d;

    std::vector<math::Vector2f> vertices = {
        {-50.f, -25.f},
        {50.f, -25.f},
        {75.f, 50.f},
        {0.f, 100.f},
        {-75.f, 50.f}
    };

    math::ConvexPolygon convPolygon(vertices);
    graphics::MeshData2D::shared meshData = std::make_shared<graphics::MeshData2D>(convPolygon);
    graphics::Mesh2D mesh;
    mesh.setMeshData(meshData);
    mesh.buildMesh();

    sf::RenderWindow window(sf::VideoMode(800, 600), "main.cpp");
    sf::Clock timer;
    sf::Event event;
//  SFML

    sf::Time dt;
    while (window.isOpen()) {
        if (timer.getElapsedTime() > sf::milliseconds(10.f)) {
            dt = timer.restart();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            window.draw(mesh);
            window.display();
        }

    }

    return 0;
} // Main function