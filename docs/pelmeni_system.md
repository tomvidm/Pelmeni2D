# System module specifications
The system module is the main module which handles the internal logic.

## Classes
### Instance
The Instance is an instantiation of a program and is resposible for:
* Creating a window
* Handling the main game loop
* Communicating with states

## Design considerations
### Layers
At any point in time, the game engine is in a State. As of now, a State is just a class which encapsulates game logic that changes with time and user input. When a user clicks the mouse button somewhere on the screen, there may be many Nodes in the SceneGraph listening for this event. 

**Problem 1**: If a user is in the menu, objects in the game world should not be required to respond to this event. 

**Problem 2**: The user clicks on a GUI element, which is always in the foreground. Objects in the game world is not required to respond.

**Naive solution**: A naive solution would be to change the objects response in the case the user is in the menu or if the click was on a GUI element, but that would require the objects to know what the user is doing. This creates a circular dependency.

**Possible solution to both**:
Consider the following ordering of graphical elements which may want to respond to a click on the screen.
1. GUI
2. Units on a square grid
3. The square grid itself
Because the SceneGraph is coupled to the Instance, let's keep a transparent stack of "Layers". Layers of interactivity?

If a user clicks on the screen, the GUI should be the first to respond. If there is no response, pass the event down the stack. Each layer associates its own InputManager, so that a click event is only passed to relevant listeners. This avoids the problem of sending an event to every single Node which may listen. In the case of a tile based game with lots of units on top of the terrain, this can improve some things. (Although this is already solved by using quadtrees)

So: Let the Instance keep a list of "Layers" and always pass an event to the topmost active layer first. Then, proceed downwards. As each InputManager already keeps a map of events to the listeners, this should not cause any trouble.