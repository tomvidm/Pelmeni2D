#include "Instance.hpp"

 #define NUMOBJ 1000

namespace p2d { namespace system {
    Instance::Instance() {
         
        for (int i = 0; i < NUMOBJ; i++) {
            std::string objectId = "obj" + std::to_string(i);
            objectManager.loadObject(objectId, "testobj01");
            objectManager.getObject(objectId)->setAnimation("anim03");
        }
        
        framePeriod = sf::milliseconds(16);
        window.create(sf::VideoMode(800, 600), "Window");
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
            state.update();

            inputManager.collectInputEvents(window);
            for (int i = 0; i < NUMOBJ; i++) {
                    std::string objectId = "obj" + std::to_string(i);
                    objectManager.getObject(objectId)->update();
            }

            if (frameTimer.getElapsedTime() > framePeriod) {
                frameTimer.restart();
                window.clear();
                for (int i = 0; i < NUMOBJ; i++) {
                    std::string objectId = "obj" + std::to_string(i);
                    window.draw(objectManager.getObject(objectId)->getSprite());
                }
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d