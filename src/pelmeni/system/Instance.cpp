#include "Instance.hpp"

namespace p2d { namespace system {
    Instance::Instance() {

        // TESTING
        tex.loadFromFile("../resources/textures/link01.png");
        sprite.setSpriteTexture("link01");
        // TESTING
        
        framePeriod = sf::milliseconds(16);
        window.create(sf::VideoMode(800, 600), "Window");
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
            state.update();

            inputManager.collectInputEvents(window);

            if (frameTimer.getElapsedTime() > framePeriod) {
                frameTimer.restart();
                window.clear();
                window.draw(sprite);
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d