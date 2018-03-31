#pragma once

#include <stack>
#include <map>
#include <memory>

#include "SFML/Window.hpp"

#include "system/Component.hpp"
#include "MouseInputManager.hpp"

namespace p2d { namespace input {
    class InputManager {
    public:
        void collectInputEvents(sf::Window& window);
        void notifyListeners(const InputEvent& inputEvent);


        InputEvent onEvent(const sf::Event& sfmlEvent);
    private:
        std::multimap<InputEvent, std::shared_ptr<system::Component>> eventListenerMap;

        MouseInputManager mouseInputManager;
    }; // MouseInputManager
} // namespace input
} // namespace p2d