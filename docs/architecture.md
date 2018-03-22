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

## FPS Handling
If a lag spike occurs, the frame rate limiting control block will certainly ring true, and a larger than usual float will be passed for physics updates etc. This can cause undesired behaviour:
* Things going through walls
* Things behaving weirdly

This must somehow be handled should the need arise. One simple solution is to implement a very strict fps limiter where low FPS will cause the maximum amount of time passed each frame (in terms of gameplay) is the framelimiter - so a frame that renders in 40ms when the normal FPS is limited to a frame period of 16ms should still pass a float corresponding to 16ms to phsyics updates. This will cause the effect of slow motion, but will not necessitate braking the rules for these cases. 