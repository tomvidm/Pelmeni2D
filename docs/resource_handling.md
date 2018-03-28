# Resource handling
## ResourceManager
### ResourceMap
Each resource is stored in some container. Although at this point is it a map, this can be changed if future profiling says so.
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