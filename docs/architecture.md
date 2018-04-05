# Achitecture
## Scene
When a scene is constructed, stack memory is allocated based on the defined values in `system/EngineDefs.hpp`, depending on which containers are used to store and access resources. As of `05.04.2018`, the main method will be through the use of maps and unordered maps for simple retrieval based on string aliases.

The Scene class contains the following members for storage and access to resources and objects:
* BlueprintManager
* TextureManager
* SpritePackManager
* EntityManager

In addition, the Scene class should have access to the EntityFactory.

The Scene object must be constructed with a path to a "scene file" as an argument. During construction, the contents of this file will be read and the Scene will be constructed according to the contents.

### Scenefile
The scene file defines the following:
* Lists of resources to prefetch
* List of scene objects to construct and initializa, along with their initial states

### EntityFactory
When a game instance asks the Scene to create an Entity, it does so by calling Scene::createEntity. This function will call EntityFactory::createEntity along with pointers to the managers as pointers. This way, the ENtityFactory will be able to access the necessary resources to create an entry. The created entity will be moved to the EntityManagers entity container.

## The entity
The entity is a lightweight object which can be accessed through ENtityManager either by a numeric id, or a string name.
THe entity is stored in an unordered map structure.
The entity should contain:
* Its ID
* Its alias (if applicable)
* Index/id to its various components
  * Transform
  * SpritePack
* An update method to be called on updates

If an entity needs to respond to some input event, the entity has to be subscribed to the specific event. When the event is registered, the EventManager will notify the entity. The entitys behaviour on an event will be defined in an object blueprint. (Or somewhere else?)

``` json
{
    "blueprint_id": "some_id",
    "behaviour": {
        "input": [
            "onKey_W": {
                "move": [1, 0, 0]
            },
            "onKey_S": {
                "move": [-1, 0, 0]
            }
        ],
        "scene": [
            "init": {
            "setAnimation": "default",
            "setTransform": [[0, 0, 0],
                             [0, 0, 0],
                             [0, 0, 0]],
            },
        ]
    }
}
```
## Blueprint
A blueprint is a data structure containing the ids/aliases to resources used by the object it describes.

## SpritePack
A SpritePack contains a mapping of aliases and frame sequences, to be used for accessing animations.