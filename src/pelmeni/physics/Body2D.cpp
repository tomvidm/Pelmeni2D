#include <cstdio>

#include "physics/Body2D.hpp"

namespace p2d { namespace physics {
    Body2D::Body2D()
    : mass(1.f), momentOfInertia(1.f),
      angularVelocity(0.f), velocity(math::Vector2f(0.f, 0.f)) {;}
    void Body2D::setMass(const float& m) {
        mass = m;
    } // setMass

    void Body2D::setMomentOfInertia(const float& I) {
        momentOfInertia = I;
    } // setMomentOfInertia

    void Body2D::setCenterOfMass(const math::Vector2f& com) {
        setOrigin(com);
    } // setCenterOfMass

    void Body2D::setAngularVelocity(const float& angularVel) {
        angularVelocity = angularVel;
    } // setAngularVelocity

    void Body2D::setVelocity(const math::Vector2f& vel) {
        velocity = vel;
    } // setVelocity

    void Body2D::applyForce(const Force2& force, const float& dt) {
        applyImpulse(force * dt);
    } // applyImpulse
    
    void Body2D::applyForce(const Force2& force, const math::Vector2f& forceLocation, const float& dt) {
        applyImpulse(force * dt);
        applyTorque(math::cross(force, forceLocation), dt);
    } // applyForce

    void Body2D::applyTorque(const float& torque, const float& dt) {
        applyAngularImpulse(torque * dt);
    }

    void Body2D::applyImpulse(const Impulse2& impulse) {
        velocity += impulse / mass;
    } // applyImpulse

    void Body2D::applyAngularImpulse(const float& angularImpulse) {
        angularVelocity += angularImpulse / momentOfInertia;
    } // applyAngularImpulse

    void Body2D::applyTime(const float& time) {
        move(velocity * time);
        rotate(angularVelocity * time);
    } // applyTime
} // namespace physics
} // namespace p2d