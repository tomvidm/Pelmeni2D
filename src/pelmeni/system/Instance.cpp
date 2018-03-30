#include "Instance.hpp"

 #define NUMOBJ 1000

namespace p2d { namespace system {
    Instance::Instance() {
        framePeriod = sf::milliseconds(16);
        window.create(sf::VideoMode(800, 600), "Window");
        objects.push_back(objectManager.createFromBlueprint("test", "test01"));
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
            inputManager.collectInputEvents(window);

            if (frameTimer.getElapsedTime() > framePeriod) {
                frameTimer.restart();
                window.clear();
                for (auto objPtr : objects) {
                    objPtr->update();
                    window.draw(objPtr->getSprite());
                }
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d