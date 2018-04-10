# Pelmeni2D
## Introduction
Pelmeni2D is a hobby side project of mine, with the goal of making it a functional framework to create isometric 3D games with. So far, this is way wayyy from finished in any interpretation of the word, but contain functional pieces which more or less work in isolation, and in some cases, in concert with other pieces

Pelmeni2D is built on top of SFML and uses many of the features SFML uses. The plan is to slowly replace those features with 3D analogues, although the 3D aspect will be mostly limited to transforming in 3D space before projecting onto the XY plane.
## Features so far
* Custom math classes, because wasting time on boiler plate is fun
* A simple framework for a sprite animation
* Simple loading of objects and resources using JSON files
* A half flexible system of transforms, both 2D and 3D
* An custom implementation of sprites, in parallel to SFML sprites, to allow for sprites to exist in 3D space.
* Fixed axis rotation and quaternion rotation
## Requirements
This is written and tested on Ubuntu 16.04 LTE. Any other platform requires work on the build system.
### Prerequisites
* [SFML 2.4+](https://www.sfml-dev.org/)
* [CMake 3.0+](https://cmake.org/)
* [rapidjson](https://github.com/Tencent/rapidjson)
* [Google Testing Framework](https://github.com/google/googletest)

SFML and CMake should be available to the system.

`rapidjson` and `Google Testing Framework` should be git cloned into a folder `external` in the root project folder.
To build, simply enter the following command
```
mkdir build && cmake ..
```