#include "physics/Body2D.hpp"
#include "physics/Spring2D.hpp"

namespace p2d { namespace physics {
    Spring2D::Spring2D()
    : springConstant(1.f), internalFriction(1.f), equilibriumLength(1.f) {
        ;
    }

    Spring2D::Spring2D(const float& sConstant, const float& friction, const float& eqLength)
    : springConstant(sConstant), internalFriction(friction), equilibriumLength(eqLength) {
        ;
    }

    void Spring2D::setSpringConstant(const float& sConstant) {
        springConstant = sConstant;
    }

    void Spring2D::setInternalFriction(const float& fric) {
        internalFriction = fric;
    }

    void Spring2D::setEquilibriumLength(const float& eqLength) {
        equilibriumLength = eqLength;
    }

    Force2 Spring2D::calculateForce(Body2D& body0, Body2D& body1) const {
        const math::Vector2f displacement = body1.getPosition() - body0.getPosition();
        const math::Vector2f normalizedDisplacement = math::normalize(displacement);
        const float absDisplacement = math::magnitude(displacement) - equilibriumLength;

        const math::Vector2f relativeVelocity = body1.getVelocity() - body0.getVelocity();

        const Force2 springForce = -normalizedDisplacement * springConstant * absDisplacement;
        const Force2 springFriction = -normalizedDisplacement * internalFriction * math::dot(relativeVelocity, normalizedDisplacement);
        return springForce + springFriction;
    }
} // namespace physics
} // namespace p2d