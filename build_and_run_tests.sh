#!/bin/bash

set -e

cd build && make && ./test/p2d-ut && cd ..