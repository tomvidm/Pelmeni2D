#pragma once

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "../input/InputManager.hpp"
#include "../utility/ResourceManager.hpp"
#include "../graphics/Sprite.hpp"

namespace p2d { namespace system {
    class Instance {
    public:
        Instance();
        void run();

        /*
            FOR TESTIGN
        */

        graphics::Sprite sprite;
        sf::Texture tex;
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