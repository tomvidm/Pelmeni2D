#include "gtest/gtest.h"

#include "math/Transform3.hpp"
#include "math/Vector.hpp"

#include "../Helpers.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestTransform, TransformWorksFine) {
        const float pi = 3.141592f;
        Transform3 Transform3::Translation(1.f, 1.f, 1.f);

        Vector3f u(1.f, 1.f, 1.f);
        Vector3f v(1.f, 1.f, 0.f);

        
    }
}
}
}