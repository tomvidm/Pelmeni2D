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
#include "animation/Keyframe.hpp"
#include "animation/Animation.hpp"
#include "input/InputManager.hpp"

#include "graphics/AnimatedSprite.hpp"

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

    auto k0 = animation::Keyframe{
        sf::seconds(3.f),
        animation::Frame{
            math::Vector2f(100.f, 100.f),
            math::Vector2f(4.f, 1.f),
            0.f
        }
    };

    auto k1 = animation::Keyframe{
        sf::seconds(3.f),
        animation::Frame{
            math::Vector2f(500.f, 500.f),
            math::Vector2f(3.f, 3.f),
            math::fromAngle(90.f)
        }
    };

    auto k2 = animation::Keyframe{
        sf::seconds(3.f),
        animation::Frame{
            math::Vector2f(500.f, 200.f),
            math::Vector2f(5.f, 5.f),
            math::fromAngle(210.f)
        }
    };

    std::vector<animation::Keyframe> keyframes = {k0, k1, k2, k0, k1, k2};
    animation::Animation anim(keyframes);

    tmgr.loadTexturesFromList("textures/test_textures.json");
    spmgr.loadSpritePacksFromList("sprites/test_sprites.json", &tmgr);

    graphics::AnimatedSprite sprite;
    sprite.setSpritePack(spmgr.get("link"));
    sprite.setSpriteAnimation("default");
    sprite.setPosition(math::Vector2f(800.f * randf(), 600.f * randf()));
    sprite.setAnimation(anim);

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
            sprite.update(dt);
            window.draw(sprite);
            window.display();
        }

    }

    return 0;
} // Main function