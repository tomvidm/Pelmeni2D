#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "input/InputManager.hpp"
#include "system/ObjectManager.hpp"

namespace p2d { namespace system {
    class Instance {
    public:
        Instance();
        void run();

        /*
            FOR TESTIGN
        */

        
    private:
        input::InputManager inputManager;
        system::ObjectManager objectManager;

        sf::RenderWindow window;
        sf::Clock frameTimer;
        sf::Time framePeriod;
        sf::Event event;

        std::vector<p2d::system::Object::ptr> objects;
    }; // class State
} // namespace system
} // namespace p2d