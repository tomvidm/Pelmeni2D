# Graphics specifications
## Animation
* The Frame defines the duration of one sprite animation frame and the rectangle covering the desired part of a texture.
* The FrameSequence class holds a vector of Frame objects and should be referenced through the AnimationMap object.
* The AnimationState stores a pointer to a specific FrameSequence, corresponding to the current animation. AnimationState should also store an integer pointing to the currect Frame as well as a clock for timing the animation.
* The Sprite class should inherit from sf::Sprite and should have AnimationState as an additional variable. The Sprite class should have an extended interface for handling animations.

## Sprite Interface
### Setting a texture on a Sprite
Setting a texture on a Sprite is currently simple (but rigid). Given a `.png` located in `resources/textures/` (e.g `resources/textures/###.png`), the id `###` should be passed to the `Sprite::setSpriteTexture` of a Sprite instance.

All Sprites share (so far) a common TextureManager and AnimationMap. This should change later, to give way for a layered management of resources. 

Here is the flow:
1. Someone called `setSpriteTexture("abc")` on a Sprite instance
2. The Sprite instance asks the TextureManger for a texture with the id "abc". Due to how the ResourceMap template class works, it first checks if the given id is already mapped to a texture. If no, load the texture and map the id to it - else, return the mapped texture.
3. The Sprite calls sf::Sprite::setTexture using the retrieved texture.

### Loading spritesheet and animation data based on id
Instead of loading textures and frame sequences separately, this should be handled by one command. We define a "package" as both the spritesheets, the frame data and other useful information related to some set of visuals. A character sprite may have multiple animations using the same spritesheet, which all can be related by some base id `"abc"`.

This should be enough for some ResourceMap to load a file `"abc.lua"` and read additional data from a table stored in that file.

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


## TextureManager