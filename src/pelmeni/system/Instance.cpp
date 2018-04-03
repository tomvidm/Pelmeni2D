#include "Instance.hpp"

namespace p2d { namespace system {
    Instance::Instance() {
        framePeriod = sf::milliseconds(16);
        window.create(sf::VideoMode(800, 600), "Window");
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
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