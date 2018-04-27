#include <iostream>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <tuple>
#include <array>


#include "SFML/Graphics.hpp"

#include "graphics/TextureManager.hpp"
#include "graphics/SpritePackManager.hpp"
#include "input/InputManager.hpp"

#include "graphics/Sprite.hpp"

float randf() {
    const float r = static_cast<float>(rand());
    const float r_max = static_cast<float>(RAND_MAX);
    return r / r_max;
}

int main() {
    using namespace p2d;

    srand(time(NULL));
    input::InputManager inputManager;
    graphics::TextureManager tmgr;
    graphics::SpritePackManager spmgr;

    tmgr.loadTexturesFromList("textures/test_textures.json");
    spmgr.loadSpritePacksFromList("sprites/test_sprites.json", &tmgr);

    std::array<graphics::Sprite, 200> sprites;
    for (auto& sprite : sprites) {
        sprite.setSpritePack(spmgr.get("test_sprite01"));
        sprite.setAnimation("default");
        sprite.setPosition(math::Vector2f(800.f * randf(), 600.f * randf()));
        sprite._animationState.update(sf::seconds(randf()));
    }

//  SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "main.cpp");
    sf::Clock timer;
    sf::Event event;
//  SFML

    sf::Time dt;
    while (window.isOpen()) {
        inputManager.collectInputEvents(window);
        inputManager.processEvents(window);
        if (timer.getElapsedTime() > sf::milliseconds(10.f)) {
            dt = timer.restart();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            for (auto& sprite : sprites) {
                sprite.update(dt * 0.6f);
                window.draw(sprite);
            }
            window.display();
        }

    }

    return 0;
} // Main function