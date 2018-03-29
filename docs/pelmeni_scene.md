# Scene
## Initializing scene
### Prefetching resources
When a scene is loaded, a list of needed resources are prefetched by reading the scene file. This file should be located in `path/to/resources/scenes/`.  The running game instance should already have an map of scene files accessible through their id.

The scene file should contain:
* The scene id
* A list, or a reference to a list of blueprints to prefetch
  * The blueprints contain their own lists of resources to prefetch, so the user is not required to list all the details.
* A description of the scene graph for the engine to reconstruct
  * The exact format should be decided upon through iteration, testing and trial and error