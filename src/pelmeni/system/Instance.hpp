#pragma once

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "../input/InputManager.hpp"
#include "../graphics/Sprite.hpp"
#include "ObjectManager.hpp"

namespace p2d { namespace system {
    class Instance {
    public:
        Instance();
        void run();

        /*
            FOR TESTIGN
        */

        
    private:
        State state;

        input::InputManager inputManager;
        ObjectManager objectManager;

        sf::RenderWindow window;
        sf::Clock frameTimer;
        sf::Time framePeriod;
        sf::Event event;
    }; // class State
} // namespace system
} // namespace p2d