#!/bin/bash

set -e

cd build && cmake .. && make && ./src/p2d-run && cd ..