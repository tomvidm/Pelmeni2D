# Achitecture
* Decouple game logic from engine by exposing an C++ API to LUA.

## ResourceManager
ResourceManager is a generic class responsible for mapping some string (aliased as ResourceId) to some type T. For example, TextureManager would be declared as ResourceManager<sf::Texture>.
The ResourceManager will also need a ResourceLoader as a template parameter. No inheritance or virtual functions are needed as this will be resolved at compile time.

The ResourceLoader needs the following public interface to be used with the ResourceManager. As the ResourceManger is generic, the load and release methods only needs an id to identify which resource to modify, insert or remove.
```
* ResourceType ResourceLoader::loadResource(const ResourceId& id)
```
From ResourceManager point of view, each ResourceLoader only differ in the type they return. The implementation details of each loader should be specific to the type of data, where the data is located and the operations needed to obtain the data. The ResourceLoaded can just as well retrieve data from the web, because the ResourceManager does not care how the loader works as long as it adheres to the interface and returns correct data.