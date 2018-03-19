# Input specifications
* The InputManager handles SFML's sf::Event and translates them to p2d::input::InputEvent
* A scene node can subscribe to a specific event. InputManager will get a list of all SceneNodes subscribing to a specific event and pass the event to them, so that the SceneNode itself can respond with specified behaviour.
* A SceneNode can subscribe to an input event by using SceneManager as an interface. A SceneNode should ask SceneManager using subscribeToInputEvent and passing a shared_ptr to itself. SceneManager will pass this on to InputManager which will store this in a multimap.

### MouseButtonEvent
Prerequisite: An SFML event is polled after a mouse button press.

2. `InputEventManager` polls an event from the given window
3. `InputEventManager` calls `onEvent`. This branches off and calls `onMouseButtonEvent`
4. `MouseInputManager::onMouseButtonEvent` calls `MouseState::onMouseButtonEvent` with
5. `MouseState` checks which button was pressed or released
6. The corresponding `MouseButtonState` is called from `MouseState`based on the data in the event structure. q

```

```