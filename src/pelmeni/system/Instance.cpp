#include "Instance.hpp"

#include <iostream>

namespace p2d { namespace system {
    Instance::Instance() {
        std::cout << "Running Instance()\n";
        objectManager.loadObject("obj01", "testobj01");
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
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d