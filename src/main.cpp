#include <iostream>
#include <cstdio>

#include "system/BlueprintManager.hpp"

int main() {
    p2d::system::BlueprintManager bpm;
    bpm.loadBlueprint("test01");
    return 0;
} // Main function