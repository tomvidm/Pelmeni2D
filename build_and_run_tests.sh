#!/bin/bash

set -e

cd build && cmake -DTesting=ON .. && make && ./test/p2d-ut && cd ..