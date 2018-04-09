#pragma once

#include "math/Transform3.hpp"

namespace p2d { namespace system {
    class Transformable3 {
    public:
        inline void setPosition(const math::Vector3f& vec) { position = vec; }
        inline void setOrigin(const math::Vector3f& vec) { origin = vec; }
        inline math::Vector3f getPosition() const { return position; }
        inline math::Vector3f getOrigin() const { return origin; }
        
        void setRotation(const float& x, const float& y, const float& z);
        
        math::Transform3 getTransform3() const;
    protected:
        math::Vector3f position;
        math::Vector3f origin;

        float rotationX = 0.f;
        float rotationY = 0.f;
        float rotationZ = 0.f;
    }; // class Transformable
} // namespace system
} // namespace p2d