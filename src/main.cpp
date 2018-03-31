#include <iostream>
#include <cstdio>

#include "system/Scene.hpp"

int main() {
    p2d::system::Scene scene("scenes/scene01.json");
    for (int i = 0; i < 100; i++) {
        scene.createEntity();
    }
    
    return 0;
} // Main function