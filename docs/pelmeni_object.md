# Object specifications
The GameObject is a lightweight class containing pointers to its functional components. These components includes, child objects, parent object, sprite packages encapsulating sprite animations and the source textures, as well as sounds behaviour scripts and dependent objects which it will spawn at will during its lifetime.

## Object handling
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

