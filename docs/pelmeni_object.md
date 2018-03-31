# Object specifications
Object is a lightweight data structure containing data and pointers to the functional pieces of an object in a Pelmeni2D instance. Objects are constructed from Blueprint objects.

An Object instance is created by at least two ways:
* `ObjectManager::createObject(unique_id, blueprint_id)` is called.
* Constructing directly from a Blueprint using `Object::Object(blueprint)`

An Object instance is fetched by calling `ObjectManager::get(unique_id)`

## Creating an Object instance
When `ObjectManager::createObject` is called, it first asks the BlueprintManager if it has the blueprint. If no, BlueprintManager uses its blueprint lookup table to find the necessary file and constructs a blueprint, stores it in the blueprint map and passes it back to ObjectManger.


## Object handling
### Aliases
Each object is assigned a unique id/hash for internal use, but can also optionally be associated with a string id. The object containers should have a scheme for accessing objects by their unique ids, and by aliases if they exist.
### Object Manager
The Object Manager is responsible for loading, storing and fetching objects. ObjectManager 

### Presets
Preset GameObjects are defined in lua tables in `resource/presets/foo.lua` and are loaded using the GameObjectManager. 

``` lua
gameobject = {
    object_class = "banjo"
    sprite_package = "banjo_sprite";
    sound_package = "banjo_sounds"
    behaviour_script = "some_behaviour_script";
    dependent_object = {
        "some_particle_emitter",
        "kazooie"
    }
}
```

### Loading an object

The `ObjectManager` loads an Object by using the id `foo` corresponding to a preset object defined in a lua file located in `resources/presets/foo.lua`.
``` c++
// To load an object, invoke the following method of ObjectManager
ObjectManager objMngr;
PresetId presetId = "foo";
ObjectId objectId = "foo_001";
Object obj = objMngr.loadObject(objectId, presetId);
```

The method `loadObject` will ask the `ObjectLoader` for an instance of `Object` before storing it in the object map.

### Fetching an object instance

The `ObjectManager` fetches Objects by their unique id using the method `ObjectManager::getObject(const ObjectId& uniqueId)`. This method looks up the id (key) in `ObjectManager::objectMap` and returns a reference to it if found. Otherwise, return a default constructed `Object`.

