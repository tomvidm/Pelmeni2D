#include <type_traits>

#include "gtest/gtest.h"

#include "math/Vector.hpp"
#include "utility/GridIndex.hpp"

TEST(TestUtilities, GridIndexWorksFine) {
    using namespace p2d;

    utility::GridIndex<int> gi;
    const math::Vector2f sectorSize(64.f, 64.f);
    gi.setSectorSize(sectorSize);
    gi.setResolution(8, 8);
    gi.rebuildGrid();
    gi.rebuildBoundingRect();

    
}