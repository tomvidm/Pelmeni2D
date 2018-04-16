#pragma once

#include <stack>
#include <map>
#include <memory>

#include "SFML/Window.hpp"

#include "input/InputListener.hpp"
#include "system/Component.hpp"
#include "MouseInputManager.hpp"

namespace p2d { namespace input {
    class InputManager {
    public:
        void collectInputEvents(sf::Window& window);
        void notifyListeners();
        void registerListener(const InputEventType& eventType, InputListener* listener);

        InputEvent onEvent(const sf::Event& sfmlEvent, sf::Window& window);
    private:
        std::multimap<InputEventType, InputListener*> eventListenerMap;
        std::vector<InputEvent> inputEvents;
        MouseInputManager mouseInputManager;
    }; // MouseInputManager
} // namespace input
} // namespace p2d