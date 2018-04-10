#include <cstdio>
#include <math.h>

#include "Testapp_Sprites.hpp"

#include "graphics/Sprite3.hpp"

namespace testapps {
    int Testapp_Sprites() {
        float dt;
        float t;
        p2d::graphics::Sprite3 sprite = p2d::graphics::Sprite3();
        sprite.setPosition(p2d::math::Vector3f(100.f, 100.f, 0));
        sprite.setOrigin(p2d::math::Vector3f(16.f, 16.f, 0.f));
        sprite.setScale(p2d::math::Vector3f(2.f, 2.f, 2.f));
        
        sf::Event event;
        sf::RenderWindow window(sf::VideoMode(640, 480), "Testapp_WireMesh");
        sf::Clock timer;
        while (window.isOpen()) {
            dt = timer.restart().asSeconds();
            t += dt;
            sprite.setYaw(t);
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            sprite.updateVertices();
            window.clear();
            window.draw(sprite);
            window.display();
        }

        return 0;
    };
}