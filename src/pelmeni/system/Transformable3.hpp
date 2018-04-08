#pragma once

#include "math/Transform.hpp"

namespace p2d { namespace system {
    class Transformable3
    private:
        math::Vector3f position;
        math::Vector3f origin;
    }; // class Transformable
} // namespace system
} // namespace p2d