#include <iostream>
#include <cstdio>

#include "system/BlueprintManager.hpp"
#include "graphics/SpritePackageManager.hpp"

int main() {
    p2d::system::BlueprintManager bpm;
    bpm.loadBlueprint("test01");

    p2d::graphics::SpritePackageManager spm;
    spm.loadSpritePackage("test01_sprite");
    return 0;
} // Main function