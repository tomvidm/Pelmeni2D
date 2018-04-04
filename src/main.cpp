#include <iostream>
#include <cstdio>

#include "system/Scene.hpp"
#include "utility/Quadtree.hpp"

int main() {
    p2d::system::Scene scene("scenes/scene01.json");
    p2d::utility::Quadtree<int, 6, 10> q;
    return 0;
} // Main function