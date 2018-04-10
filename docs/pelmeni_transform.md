# Transforms, Vectors and Meshes
## Relationshi to SFML
The SFML library already implements transforms and a base class for any object that will be transformed. However, the framework is only suited for pure 2D, so Pelmeni2D implements several classes itself to deal with this. First of all, P2D implements transforms for 2D and 3D, in addition to 2D, 3D and 4D vectors. The latter is only as a convenience during matrix multiplication.
## Transform3 and Transform
The Transform3 class transforms Vector3f and the Transform class transforms Vector2f. Their interfaces are almost the same.
## Transformable3 
This class is the 3D analogue of SFML sf::Transformable. 

## Transformable
This class is the analogue of SFML sf::Transformable, but will be implemented specifically for Pelmeni2D.