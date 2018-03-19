# Graphics specifications
## AnimatedSprite:
The animated sprite should be a simple extension of sf::Sprite. AnimationManager will store sequences of frames with mapping from string keys. When a Sprite is asked to change an animation to an animation with the key K, Sprite asks AnimationManager if it exists - throws an exception otherwise - and passed an iterator to the specific frame sequence to the AnimationState object.
* The Frame defines the duration of one sprite animation frame and the rectangle covering the desired part of a texture.
* The FrameSequence class holds a vector of Frame objects and should be referenced through the AnimationManager object.
* The AnimationState stores a pointer to a specific FrameSequence, corresponding to the current animation. AnimationState should also store an integer pointing to the currect Frame as well as a clock for timing the animation.
* The Sprite class should inherit from sf::Sprite and should have AnimationState as an additional variable. The Sprite class should have an extended interface for handling animations.

