#pragma once

#include "physics/Physics.hpp"

namespace p2d { namespace physics {
    class Spring2D {
    public:
        Spring2D();
        Spring2D(const float& sConstant, const float& eqLength);
        Force2 calculateForce(const math::Vector2f& displacement) const;
    private:
        float springConstant;
        float equilibriumLength;
    }; // class Spring2D
} // namespace physics
} // namespace p2d