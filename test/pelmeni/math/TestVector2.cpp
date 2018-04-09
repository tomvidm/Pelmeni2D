#include "gtest/gtest.h"

#include "math/Vector.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestVector2, Vector2WorksFine) {
        Vector2f a(1.f, 1.f);

        EXPECT_EQ(projectToX(a), Vector2f(1.f, 0.f));
        EXPECT_EQ(projectToY(a), Vector2f(0.f, 1.f));

        EXPECT_EQ(magnitudeSquared(a), 2.f);
        EXPECT_EQ(magnitude(a), sqrtf(2.f));
    }
}
}
}