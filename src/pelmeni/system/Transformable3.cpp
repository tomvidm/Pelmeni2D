#include "system/Transformable3.hpp"

namespace p2d { namespace system {
    using math::Transform3;

    Transformable3::Transformable3() 
    : position(math::Vector3f(0, 0, 0)),
      origin(math::Vector3f(0, 0, 0)),
      scale(math::Vector3f(1.f, 1.f, 1.0f)),
      rotationAxis(math::Vector3f(0.f, 0.f, 1.f)),
      facing(math::Vector3f(0.f, 0.f, 1.f)),
      angle(0.f) {
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

    void Transformable3::setRotationAxis(const math::Vector3f& vec) { 
        rotationAxis = vec; 
        needsUpdate = true;
    }

    void Transformable3::setFacing(const math::Vector3f& vec) {
        facing = vec;
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

    math::Vector3f Transformable3::getRotationAxis() const {
        return rotationAxis;
    }

    math::Vector3f Transformable3::getFacing() const {
        return facing;
    }

    float Transformable3::getAngle() const {
        return angle;
    }

    math::Transform3 Transformable3::getTransform3() {
        if (needsUpdate) {
            const math::Vector3f forward = math::normalized<float>(facing - position);
            const math::Vector3f axis = math::cross(math::Vector3f(0.f, 0.f, 1.f), forward);
            const float angle = acosf(math::dot(forward, math::Vector3f(0.f, 0.f, 1.f)));
            transform = math::Transform3::Translation(position) *
                        math::Transform3::Scaling(scale) *
                        math::Transform3::Rotation(axis, angle) *
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
}
}