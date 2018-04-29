# Pelmeni2D
## Introduction
Pelmeni2D is a hobby side project of mine, with the goal of making it an at least somewhat functional framework to create games. So far, this is way wayyy from finished in any interpretation of the word, but contain functional pieces which more or less work in isolation, and in some cases, in concert with other pieces

Pelmeni2D is built on top of SFML and uses many of the features SFML uses.
## Features so far
* Input manager for mouse events that distinguishes between press, release, click and double click
* Custom math classes, because wasting time on boiler plate is fun
* A simple framework for a sprite animation, independent of frame rate
* Simple loading of objects and resources using JSON files
* A half flexible system of transforms, both 2D and 3D
* Simple physics with Body2D and Spring2D
* A Mesh2D class for arbitrary meshes with vertices, edges and filled quads.
* A Tilemap class which renders a grid and arbitrary parts of a texture.
* Fixed axis rotation and quaternion rotation
* Bezier curves & Catmull-Rom splines
* Objects can register for specific inputs through the InputListener interface
* Interpolated keyframe animations through Animable class
## Requirements
This is written and tested on Ubuntu 16.04 LTE. Any other platform requires work on the build system.
### Prerequisites
* [SFML 2.4+](https://www.sfml-dev.org/)
* [CMake 3.0+](https://cmake.org/)
* [rapidjson](https://github.com/Tencent/rapidjson)
* [Google Testing Framework](https://github.com/google/googletest)

SFML and CMake should be already installed on the system.

`rapidjson` and `Google Testing Framework` should be git cloned into a folder `external` in the root project folder.
To build, simply enter the following command
```
mkdir build && cmake ..
```
