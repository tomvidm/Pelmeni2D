#pragma once

#include "math/Transform3.hpp"
#include "math/Transform.hpp"

namespace p2d { namespace system {
    struct EntityState {
        math::Vector2f position;
        math::Vector2f scale;
        math::Radian rotation;
    }; // struct EntityState
} // namespace system
} // namesapce p2d