#!/bin/bash

set -e

cd build && make && ./src/p2d-run && cd ..