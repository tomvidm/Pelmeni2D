# Transforms, Vectors and Meshes
## Relationshi to SFML
The SFML library already implements transforms and a base class for any object that will be transformed. However, the framework is only suited for pure 2D, so Pelmeni2D implements several classes itself to deal with this. First of all, P2D implements transforms for 2D and 3D, in addition to 2D, 3D and 4D vectors. The latter is only as a convenience during matrix multiplication.
## Transform3
Transform3 is holds a 4x4 matrix of floats in addition to static default transforms and functions to transform points and vectors.

## Transformable3
This class, inspired by sf::Transformable should be a base class for any object that will move around in world space.