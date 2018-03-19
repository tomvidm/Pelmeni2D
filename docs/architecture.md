# Achitecture
* Decouple game logic from engine by exposing an C++ API to LUA.

## ResourceManager
ResourceManager is a generic class responsible for mapping some string (aliased as ResourceId) to some type T. For example, TextureManager would be declared as ResourceManager<sf::Texture>.
The ResourceManager will also need a ResourceLoader as a template parameter. No inheritance or virtual functions are needed as this will be resolved at compile time.

The ResourceLoader needs the following public interface to be used with the ResourceManager. As the ResourceManger is generic, the load and release methods only needs an id to identify which resource to modify, insert or remove.
```
* ResourceType ResourceLoader::loadResource(const ResourceId& id)
* void ResourceLoader::releaseResource(const ResourceId& id)
```
From ResourceManager point of view, each ResourceLoader only differ in the type they return. The implementation details of each loader should be specific to the type of data, where the data is located and the operations needed to obtain the data. The ResourceLoaded can just as well retrieve data from the web, because the ResourceManager does not care how the loader works.
## Ponderings 1
Each node in a state can listen for input, and respond in a certain way.
An EventHandler object will register all listeners in a list, possibly categorized by event type. (Input event, World event, inter-node event)

Event managers
* InputEventManager
   * Fetches input events and translates them to p2d events.
   * Broadcasts events to listener States
* StateEventManager
   * Fetches events from Nodes
   * Broadcasts events to listener nodes
* 

A node can receive events by different means
* EventManager broadcasts events to listener nodes
* Node passes an event directly to child nodes
* Node passes an event to the EventManager
  * optionally

## Ponderings 2
An instance contains a structure of states. It should be a "transparent deque". Given the following stack states:
```
optionsMenuOpen       <- current state 
pauseMenuOpen       L
gameRunning         L 
```

The game is paused by the Lock (L) and the pause menu is locked.
A locked satte means that input is not captured and state changes does not happen.

When the optionsMenuOpen state is ordered to transition to the next state,
the state manager pops the state and unlocks (if locked) the next state which is pauseMenuOpen.

```
pauseMenuOpen         <- current state 
gameRunning         L 
```

Each state can have a number of flags which determines how it should act.
* A state can be locked (L), which prevents any input capture or update of contained states and objects.
* A state can be deaf (D), which prevents any input capture, but frame updates and normal logic happens as usual.
* A state can be invisible (I), which prevents any rendering process.

This can be elaborated into boolean flags
* Running
* Listening
* Visible