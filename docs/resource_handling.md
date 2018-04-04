# Resource handling
A resource, from the point of view of a resource handling interface, is something that can be stored and retrieved by an index or a key. The distinction between a key and an index should be transparent to the interface - meaning, a resource can be stored in a map, as well as in a vector, but the process of storing and retrieving it should be agnostic to the details of how the resource is stored.
## Resource manager
A resource should be handled by a class based on the specified interface. 
### BlueprintManager
A blueprint manager obtains blueprints from one or more blueprint lists. Each loaded blueprint is stored, mapped by its key/id. A blueprint will be used by the EntityManager to create an entity. The created entity will be without state, which should be provided by some other way.
### TextureManager
A texture manager obtains textures for one or more texture lists. Each texture is stored and mapped by its key/id. 
### ResourceMap
### ResourceLookupTable
The task of the ResourceManager is to handle resources based on their unique id. Each external resource is defined in a lookup table, which is loaded at construction. The lookup tables look like this:
``` json
[
    ["resource01", "path_to_resource01"],
    ["resource02", "path_to_resource02"]
]
```
This simplifies the interface, for example by letting the ObjectManager construct an object first time only by using the blueprint id, instead of requiring some specific format or requiring a full path as an argument.
## ResourceLoader