#include "Instance.hpp"

namespace p2d { namespace system {
    Instance::Instance() {
        scene.loadSceneFile("scenes/scene01.json");
        framePeriod = sf::milliseconds(16);
        window.setVerticalSyncEnabled(false);
        window.create(sf::VideoMode(800, 600), "Window");
        
        run();
    } // constructor
    
    void Instance::run() {
        while (window.isOpen()) {
            inputManager.collectInputEvents(window);
            if (frameTimer.getElapsedTime() > framePeriod) {
                sf::Time frameTime = frameTimer.restart();
                window.clear();
                for (auto& entity : scene.getEntityList()) {
                    entity.update(frameTime);
                    window.draw(entity.getSprite());
                }
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d