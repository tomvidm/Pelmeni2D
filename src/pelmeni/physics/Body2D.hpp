#pragma once

#include "physics/Physics.hpp"
#include "math/Vector.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace physics {
    class Body2D : public system::Transformable2 {
    public:
        Body2D();
        
        void setMass(const float& m);
        void setMomentOfInertia(const float& I);
        void setCenterOfMass(const math::Vector2f& com);
        void setAngularVelocity(const float& angVel);
        void setVelocity(const math::Vector2f& vel);

        void applyForce(const Force2& force, const math::Vector2f& forceLocation, const float& dt);
        void applyForce(const Force2& force, const float& dt);
        void applyTorque(const float& torque, const float& dt);
        void applyImpulse(const Impulse2& impulse);
        void applyAngularImpulse(const float& angularImpulse);
        void applyTime(const float& time);
    private:
        float mass;
        float momentOfInertia;

        float angularVelocity;
        math::Vector2f velocity;
    }; // class Body2D
} // namespace physics
} // namespace p2d