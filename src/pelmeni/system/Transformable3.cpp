#include "system/Transformable3.hpp"

namespace p2d { namespace system {
    using math::Transform3;

    Transformable3::Transformable3() 
    : position(math::Vector3f(0, 0, 0)),
      scale(math::Vector3f(1.f, 1.f, 1.f)),
      origin(math::Vector3f(0, 0, 0)) {
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

    math::Vector3f Transformable3::getPosition() const {
        return position;
    }

    math::Vector3f Transformable3::getOrigin() const {
        return origin;
    }

    math::Vector3f Transformable3::getScale() const {
        return scale;
    }

    math::Transform3 Transformable3::getTransform3() {
        if (needsUpdate) {
            transform = math::Transform3(
                scale.x, 0, 0, position.x - origin.x*scale.x,
                0, scale.y, 0, position.y - origin.y*scale.y,
                0, 0, scale.z, position.z - origin.z*scale.z,
                0, 0, 0, 1);

            needsUpdate = false;
        }

        return transform;
    }
}
}