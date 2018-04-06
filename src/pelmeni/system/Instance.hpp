#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "system/Scene.hpp"
#include "input/InputManager.hpp"

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
        system::Scene scene;
        sf::RenderWindow window;
        sf::Clock frameTimer;
        sf::Time framePeriod;
        sf::Event event;
    }; // class State
} // namespace system
} // namespace p2d