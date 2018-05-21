# Animation specifications
The animation system is divided into two main parts: Sprite animation, and keyframe interpolation animation.

## Sprite Animation
## Keyframe animation
Defined in the namespace `p2d::animation`. 
Animations are based on the class `p2d::animation::Animation` which contains a sequence of keyframes, and variables for keepign track of the state of the animation. The class Animable is designed to be a base class for any object that can be animated, through a simple interface. Animable also inherits from Transformable2, so that Animable will override any attempt at changing the internal transform states during an animation.