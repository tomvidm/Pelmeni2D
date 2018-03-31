# Entity-Component system
## The entity
The entity is a lightweight object which can be accessed through ENtityManager either by a numeric id, or a string name.
THe entity is stored in an unordered map structure.
The entity should contain:
* Its ID
* Its alias (if applicable)
* Index/id to its various components
  * Transform
  * Texture
  * Animation
  * Behaviour
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