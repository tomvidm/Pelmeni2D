#include "system/Transformable3.hpp"

namespace p2d { namespace system {
    using math::Transform3;

    Transformable3::Transformable3() 
    : needsUpdate(true),
      position(math::Vector3f(0, 0, 0)),
      origin(math::Vector3f(0, 0, 0)),
      scale(math::Vector3f(1.f, 1.f, 1.f)),
      facing(math::Vector3f(0.f, 0.f, 1.f)),
      angle(0.f),
      rollAngle(0.f) {
        needsUpdate = true;
    }

    void Transformable3::setPosition(const math::Vector3f& vec) { 
        position = vec;
        needsUpdate = true;
    }

    void Transformable3::setOrigin(const math::Vector3f& vec) { 
        origin = vec; 
        needsUpdate = true;
    }

    void Transformable3::setScale(const math::Vector3f& vec) { 
        scale = vec; 
        needsUpdate = true;
    }

    void Transformable3::setFacing(const math::Vector3f& vec) {
        facing = math::normalized<float>(vec);
        needsUpdate = true;
    }

    void Transformable3::setAngle(const float& val) {
        angle = val;
        needsUpdate = true;
    }

    math::Vector3f Transformable3::getPosition() const {
        return position;
    }

    math::Vector3f Transformable3::getOrigin() const {
        return origin;
    }

    math::Vector3f Transformable3::getScale() const {
        return scale;
    }

    math::Vector3f Transformable3::getFacing() const {
        return facing;
    }

    float Transformable3::getAngle() const {
        return angle;
    }

    void Transformable3::move(const math::Vector3f& vec) {
        position += vec;
        needsUpdate = true;
    }

    void Transformable3::rotate(const math::Vector3f& axis, const float& angle) {
        const math::Quaternion<float> q_rotate(math::normalized<float>(axis), angle);
        facing = math::Transform3::Rotation(q_rotate).transformVector(facing);
        needsUpdate = true;
    }

    void Transformable3::roll(const float& arg) {
        rollAngle += arg;
        needsUpdate = true;
    }

    math::Transform3 Transformable3::getTransform3() {
        if (needsUpdate) {
            const math::Vector3f axis = math::cross(forward, facing);
            const float angle = acosf(math::dot(forward, facing));
            const math::Quaternion<float> q_facing(axis, angle);
            const math::Quaternion<float> q_roll(math::normalized<float>(facing), rollAngle);
            
            transform = math::Transform3::Translation(position) *
                        math::Transform3::Scaling(scale) *
                        math::Transform3::Rotation(q_roll) * 
                        math::Transform3::Rotation(q_facing) *
                        math::Transform3::Translation(-origin);
/* 
            transform = math::Transform3(
                scale.x, 0, 0, position.x - origin.x*scale.x,
                0, scale.y, 0, position.y - origin.y*scale.y,
                0, 0, scale.z, position.z - origin.z*scale.z,
                0, 0, 0, 1);
 */
            needsUpdate = false;
        }

        return transform;
    }

    const math::Vector3f Transformable3::forward = math::Vector3f(0.f, 0.f, 1.f);
}
}