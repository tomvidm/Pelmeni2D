# Pelmeni2D
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