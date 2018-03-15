#pragma once

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "../event/EventManager.hpp"

namespace p2d { namespace system {
    class Instance {
    public:
        Instance();
        void run();
    private:
        State state;

        event::EventManager eventManager;

        sf::RenderWindow window;
        sf::Clock frameTimer;
        sf::Time framePeriod;
        sf::Event event;
    }; // class State
} // namespace system
} // namespace p2d