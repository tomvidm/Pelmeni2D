# GameObject specifications
The GameObject is a lightweight class containing pointers to its functional components.

## Loading a preset GameObject
Preset GameObjects are defined in lua tables in resource/gameobjects/###.lua and are loaded using the GameObjectManager. The functionality is similar to PackageManager, as each GameObject is stored in a map and retrieved by an id.

``` lua
gameobject = {
    sprite_package = "sprite_package_id";
}
```