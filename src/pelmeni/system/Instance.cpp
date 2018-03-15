#include "Instance.hpp"

namespace p2d { namespace system {
    Instance::Instance() {
        framePeriod = sf::milliseconds(16);
        window.create(sf::VideoMode(800, 600), "Window");
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
            state.update();

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } // if
            } // while

            if (frameTimer.getElapsedTime() > framePeriod) {
                frameTimer.restart();
                window.clear();
                //state.renderToBuffer();
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d