# Graphics specifications
## Animation
* The Frame defines the duration of one sprite animation frame and the rectangle covering the desired part of a texture.
* The FrameSequence class holds a vector of Frame objects and should be referenced through the AnimationMap object.
* The AnimationState stores a pointer to a specific FrameSequence, corresponding to the current animation. AnimationState should also store an integer pointing to the currect Frame as well as a clock for timing the animation.
* The Sprite class should inherit from sf::Sprite and should have AnimationState as an additional variable. The Sprite class should have an extended interface for handling animations.

## Packages
A package is a set of resources related to some name. For example, a spritesheet can be associated with some set of frame sequences through a package. As a first iteration in Pelmeni2d, a package should define the following fields:
``` lua
package = {
    name = "package_name";
    texture = "path/to/texture/texture_name.png"
    frame_sequences = {
        {
            frame_sequence_name = "anim01";
            {
                T               -- int
                {x, y},         -- {int, int}
                {xsize, ysize}  -- {int, int}
            }, -- next frame here
        }
    }
}
```
* When the PackageManager loads a package, it first collects the name of the texture. It checks with the TextureManager for any duplicated and loads it if needed. When the PackageManager is loading a package, it stores a shared pointer to the actual `sf::Texture` and packs it into the Package to be returned by the loadResource function. 
* Because one texture can contain the animation frames for different object and characters, the texture must be separated from the named animations related to one package.
* The animations are loaded by the AnimationLoader and stored into the animation map of the package.