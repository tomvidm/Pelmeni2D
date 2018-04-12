#include "physics/Spring2D.hpp"

namespace p2d { namespace physics {
    Spring2D::Spring2D()
    : springConstant(1.f), equilibriumLength(1.f) {
        ;
    }

    Spring2D::Spring2D(const float& sConstant, const float& eqLength)
    : springConstant(sConstant), equilibriumLength(eqLength) {
        ;
    }

    Force2 Spring2D::calculateForce(const math::Vector2f& displacement) const {
        const float absDisplacement = math::magnitude(displacement) - equilibriumLength;
        const math::Vector2f normalizedDisplacement = math::normalize(displacement);
        return -normalizedDisplacement * springConstant * absDisplacement;
    }
} // namespace physics
} // namespace p2d