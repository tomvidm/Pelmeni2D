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
    using p2d::math::toString;
    using p2d::math::Vector2f;
    
    Vector2f vec(1.f, 1.f);
    Transform A = Transform::Rotation(1.5707963f);


    Vector2f a = vec;



    print(a);
    printf("%s\n", toString(A).c_str());
    a = A.transformVector(a);
    print(a);
    printf("%s\n", toString(A.inverse()).c_str());
    a = A.inverse().transformVector(a);
    print(a);
    return 0;
} // Main function