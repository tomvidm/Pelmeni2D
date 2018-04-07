#pragma once

#include "math/Transform.hpp"

namespace p2d { namespace system {
    class Transformable
    private:
        math::Vector2f position;
        math::Vector2f origin;
    }; // class Transformable
} // namespace system
} // namespace p2d