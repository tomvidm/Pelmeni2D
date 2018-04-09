#include <cstdio>
#include <math.h>

#include "Testapp_WireMesh.hpp"

namespace testapps {
    int Testapp_WireMesh() {
        printf("Running Testapp_WireMesh...\n");
        using p2d::math::Vector3f;

        p2d::graphics::Vector3List vlist = {
            100.f*Vector3f(-1.f, -0.5, 0.f),
            100.f*Vector3f(0.f, 0.f, 1.f),
            100.f*Vector3f(0.f, 1.f, 0.f),
            100.f*Vector3f(1.f, -0.5, 0.f)
        };

        p2d::graphics::EdgeList elist = {
            std::make_tuple(0, 1),
            std::make_tuple(0, 2),
            std::make_tuple(0, 3),
            std::make_tuple(1, 2),
            std::make_tuple(1, 3),
            std::make_tuple(2, 3)
        };

        p2d::graphics::WireMesh mesh(vlist, elist);
        mesh.setPosition(p2d::math::Vector3f(320.f, 240.f, 0.f));
        float rz = 0.f;
        const float drz = 2.f * M_PI / 6.f;
        
        
        sf::RenderWindow window(sf::VideoMode(640, 480), "Testapp_WireMesh");
        sf::Clock timer;
        while (window.isOpen()) {
            float dt = timer.restart().asSeconds();
            sf::Event event;
            rz += drz * dt;
            mesh.setRotation(0, 0, rz);
            mesh.transformAndProjectToXY();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(mesh);
            window.display();
        }

        return 0;
    };
}