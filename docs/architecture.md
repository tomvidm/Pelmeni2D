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

## FPS Handling
If a lag spike occurs, the frame rate limiting control block will certainly ring true, and a larger than usual float will be passed for physics updates etc. This can cause undesired behaviour:
* Things going through walls
* Things behaving weirdly

This must somehow be handled should the need arise. One simple solution is to implement a very strict fps limiter where low FPS will cause the maximum amount of time passed each frame (in terms of gameplay) is the framelimiter - so a frame that renders in 40ms when the normal FPS is limited to a frame period of 16ms should still pass a float corresponding to 16ms to phsyics updates. This will cause the effect of slow motion, but will not necessitate braking the rules for these cases. 