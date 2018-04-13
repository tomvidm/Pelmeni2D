#pragma once

#include "physics/Physics.hpp"

namespace p2d { namespace physics {
    class Spring2D {
    public:
        Spring2D();
        Spring2D(const float& sConstant, const float& friction, const float& eqLength);
        
        void setSpringConstant(const float& sConstant);
        void setInternalFriction(const float& fric);
        void setEquilibriumLength(const float& eqLength);

        Force2 calculateForce(Body2D& body0, Body2D& body1) const;
    private:
        float springConstant;
        float internalFriction;
        float equilibriumLength;
    }; // class Spring2D
} // namespace physics
} // namespace p2d