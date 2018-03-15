#!/bin/bash

set -e

mkdir -p build
mkdir -p external

# create build directory and run cmake
cd build && cmake .. && cd ..
