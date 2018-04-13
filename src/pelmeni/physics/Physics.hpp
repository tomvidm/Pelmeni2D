#pragma once

#include "math/Vector.hpp"

namespace p2d { namespace physics {
    using Force2 = math::Vector2f;
    using Force3 = math::Vector3f;
    using Impulse2 = math::Vector2f;
    using Impulse3 = math::Vector3f;

    Force2 getDrag(const math::Vector2f& velocity, const float& dragConstant);
} // namespace physics
} // namespace p2d