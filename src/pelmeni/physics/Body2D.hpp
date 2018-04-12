#pragma once

#include "physics/Physics.hpp"
#include "math/Vector.hpp"
#include "system/Transformable2.hpp"

namespace p2d { namespace physics {
    class Body2D : public system::Transformable2 {
    public:
        Body2D(const math::Vector2f& initialPosition,
               const float& initialMass, 
               const float& initialMoment,
               const float& initialAngularVelocity,
               const math::Vector2f& initialVelocity);
        
        Body2D();
        
        Body2D(const math::Vector2f initialPosition,
               const float& initialMass);
        
        void setMass(const float& m);
        void setMomentOfInertia(const float& I);
        void setCenterOfMass(const math::Vector2f& com);
        void setAngularVelocity(const float& angVel);
        void setVelocity(const math::Vector2f& vel);
        void setFixed(const bool& fix);

        void applyForce(const Force2& force, const math::Vector2f& forceLocation, const float& dt);
        void applyForce(const Force2& force, const float& dt);
        void applyTorque(const float& torque, const float& dt);
        void applyImpulse(const Impulse2& impulse);
        void applyAngularImpulse(const float& angularImpulse);
        void applyTime(const float& time);

        float getEnergy() const;
        inline float getMass() const { return mass; }
        inline float getMoment() const { return momentOfInertia; }
        inline float getAngularVelocity() const { return angularVelocity; }
        inline math::Vector2f getVelocity() const { return velocity; }
    private:
        bool fixed;
        float mass;
        float momentOfInertia;

        float angularVelocity;
        math::Vector2f velocity;
    }; // class Body2D
} // namespace physics
} // namespace p2d