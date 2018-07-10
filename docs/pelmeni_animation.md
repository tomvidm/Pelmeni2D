# Animation specifications
The animation system is divided into two main parts: Sprite animation, and keyframe interpolation animation.

## Sprite Animation
Defined in the namespace `p2d::animation`.
Sprite animations are based on the `AnimatedSprite` class, which requires the user to set the `SpritePack` member variable. The `SpritePack` class holds a texture and a mapping between animation names and frame sequences. This allows for a simple interface for switching between animations.

The sprite animations are updated using the `update` method, which requires an `sf::Time` parameter to be given. This should normally correspond to the main loop timer.
## Keyframe animation
Defined in the namespace `p2d::animation`. 
Animations are based on the class `p2d::animation::Animation` which contains a sequence of keyframes, and variables for keeping track of the state of the animation. The class Animable is designed to be a base class for any object that can be animated, through a simple interface. Animable also inherits from Transformable2, so that Animable will override any attempt at changing the internal transform states during an animation.

Limitations of the current implementation:
* Parameters that can be animated are hardcoded.