#include <iostream>
#include <cstdio>

#include "system/Instance.hpp"
#include "utility/Quadtree.hpp"
#include "math/Transform.hpp"

void print(const p2d::math::Vector2f vec) {
    printf("[%f, %f]\n", vec.x, vec.y);
}

int main() {
    //p2d::system::Instance instance;
    using p2d::math::Transform;
    using p2d::math::Vector2f;
    
    Vector2f vec(1.f, 1.f);
    Transform rot = Transform::Rotation(1.5708f);
    Transform translate = Transform::Translate(1.f, 1.f);

    Vector2f a = vec;
    Vector2f b = vec;

    a = translate.transformVector(a);
    a = rot.transformVector(a);

    Transform composite = translate * rot;

    b = composite.transformVector(b);

    print(a);
    print(b);
    return 0;
} // Main function