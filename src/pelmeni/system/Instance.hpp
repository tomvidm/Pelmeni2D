#pragma once

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "../input/InputManager.hpp"

namespace p2d { namespace system {
    class Instance {
    public:
        Instance();
        void run();
    private:
        State state;

        input::InputManager inputManager;

        sf::RenderWindow window;
        sf::Clock frameTimer;
        sf::Time framePeriod;
        sf::Event event;
    }; // class State
} // namespace system
} // namespace p2d