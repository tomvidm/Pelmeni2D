# Object Blueprint
A blueprint is a data structure containing the essential information about some class of game objects. They are summarized in a .json file and read during object loading. The ObjectManager uses a dictionary to keep track of loaded blueprints.

## Blueprint JSON format
``` json
{
    "blueprint_id": "string identifier",
    "graphics": {
        "grapics_package_file": "path/to/file"
    }
}
```