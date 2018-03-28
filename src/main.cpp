#include <iostream>
#include <cstdio>

#include "system/ObjectManager.hpp"

int main() {
    p2d::system::ObjectManager objmanager;
    objmanager.createFromBlueprint("object01", "test01");
    return 0;
} // Main function