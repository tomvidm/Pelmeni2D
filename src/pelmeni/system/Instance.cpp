#include "Instance.hpp"

#include <iostream>

namespace p2d { namespace system {
    Instance::Instance() {
        std::cout << "Running Instance()\n";

        // TESTING
        sprite.usePackage("test01");
        // sprite.setSpriteTexture("textures/test01.png");
        sprite.setScale(4.f, 4.f);
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