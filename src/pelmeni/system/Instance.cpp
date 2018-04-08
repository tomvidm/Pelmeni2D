#include "Instance.hpp"

#include "graphics/Tilemap.hpp"

namespace p2d { namespace system {
    Instance::Instance() {
        scene.loadSceneFile("scenes/scene01.json");
        framePeriod = sf::milliseconds(16);
        window.setVerticalSyncEnabled(false);
        window.create(sf::VideoMode(800, 600), "Window");
        
        run();
    } // constructor
    
    void Instance::run() {
        graphics::Tilemap<12, 12> tilemap(math::Vector2f(16.f, 16.f), math::Vector2f(-8.f, 16.f));
        while (window.isOpen()) {
            inputManager.collectInputEvents(window);
            if (frameTimer.getElapsedTime() > framePeriod) {
                sf::Time frameTime = frameTimer.restart();
                window.clear();
                window.draw(tilemap);
                for (auto& entity : scene.getEntityList()) {
                    //entity.update(frameTime);
                    //window.draw(entity.getSprite());
                }
                window.display();
            } // if
        } // while
    } // run
} // namespace system
} // namespace p2d