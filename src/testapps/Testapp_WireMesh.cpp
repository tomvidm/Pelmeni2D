#include <cstdio>
#include <math.h>

#include "graphics/Axes.hpp"
#include "Testapp_WireMesh.hpp"

namespace testapps {
    int Testapp_WireMesh() {
        using p2d::math::Transform3;
        using p2d::math::Vector3f;

        printf("Running Testapp_WireMesh...\n");

        p2d::graphics::Vector3List vlist = {
            100.f*Vector3f(-0.5f, -0.5, 0.f),
            100.f*Vector3f(0.f, 0.f, 2.f),
            100.f*Vector3f(0.f, 0.5f, 0.f),
            100.f*Vector3f(0.5f, -0.5, 0.f),
            100.f*Vector3f(0.f, 0.f, -0.5f)
        };

        p2d::graphics::EdgeList elist = {
            std::make_tuple(0, 1),
            std::make_tuple(0, 2),
            std::make_tuple(0, 3),
            std::make_tuple(1, 2),
            std::make_tuple(1, 3),
            std::make_tuple(2, 3),
            std::make_tuple(4, 0),
            std::make_tuple(4, 2),
            std::make_tuple(4, 3)
        };


        p2d::graphics::WireMesh mesh(vlist, elist);
        mesh.setPosition(p2d::math::Vector3f(320.f, 240.f, -100.f));
        //mesh.setOrigin(p2d::math::Vector3f(100.f, -50.f, -50.f));
        mesh.setScale(p2d::math::Vector3f(1.f, 1.f, 1.f));

        float t = 0.f;
        float dt = 0.f;
        
        sf::RenderWindow window(sf::VideoMode(640, 480), "Testapp_WireMesh");
        sf::Vector2i mpos = sf::Mouse::getPosition(window);
        p2d::math::Vector3f pos = p2d::math::Vector3f(
            static_cast<float>(mpos.x - mesh.getPosition().x),
            static_cast<float>(mpos.y - mesh.getPosition().y),
            200.f
        );
        sf::Clock timer;
        while (window.isOpen()) {
            mpos = sf::Mouse::getPosition(window);
            pos = p2d::math::Vector3f(
                static_cast<float>(mpos.x - mesh.getPosition().x),
                static_cast<float>(mpos.y - mesh.getPosition().y),
                200.f
            );
            dt = timer.restart().asSeconds();
            t += dt;
            mesh.setFacing(pos);
            sf::Event event;
            mesh.transform();
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