#include "gtest/gtest.h"

#include "math/Transform.hpp"
#include "math/Vector.hpp"

#include "../Helpers.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestMath, TransformWorksFine) {
        const float pi = 3.141592f;
        Transform translate = Transform::Translate(1.f, 1.f);
        Transform rotate90DegreesCCW = Transform::Rotation(pi/2.f);
        Vector2f u = translate.transformVector(Vector2f(0.f, 0.f));
        
        EXPECT_EQ(u, Vector2f(1.f, 1.f));
        u = rotate90DegreesCCW.transformVector(u);
        EXPECT_TRUE(p2d::ut::floatCompare(u.x, -1.f));
        EXPECT_TRUE(p2d::ut::floatCompare(u.y, 1.f));
        u = inverse(rotate90DegreesCCW).transformVector(u);
        EXPECT_TRUE(p2d::ut::floatCompare(u.x, 1.f));
        EXPECT_TRUE(p2d::ut::floatCompare(u.y, 1.f));
    }
}
}
}