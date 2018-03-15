# Input specifications
Input!

### MouseButtonEvent
Prerequisite: An SFML event is polled after a mouse button press.

2. `InputEventManager` polls an event from the given window
3. `InputEventManager` calls `onEvent`. This branches off and calls `onMouseButtonEvent`
4. `MouseInputManager::onMouseButtonEvent` calls `MouseState::onMouseButtonEvent` with
5. `MouseState` checks which button was pressed or released
6. The corresponding `MouseButtonState` is called from `MouseState`based on the data in the event structure. q

```

```