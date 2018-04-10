#pragma once

#include "math/Transform.hpp"
#include "math/Transform3.hpp"

namespace p2d { namespace system {
    class Transformable3 {
    public:
        Transformable3();
        void setPosition(const math::Vector3f& vec);
        void setOrigin(const math::Vector3f& vec);
        void setScale(const math::Vector3f& vec);
        void setRotationAxis(const math::Vector3f& vec);
        void setFacing(const math::Vector3f& vec);
        void setAngle(const float& val);
        math::Vector3f getPosition() const;
        math::Vector3f getOrigin() const;
        math::Vector3f getScale() const;
        math::Vector3f getRotationAxis() const;
        math::Vector3f getFacing() const;
        float getAngle() const;
        
        math::Transform3 getTransform3();
        math::Transform getTransform();
    protected:
        bool needsUpdate;
        math::Vector3f position;
        math::Vector3f origin;
        math::Vector3f scale;
        math::Vector3f rotationAxis;
        math::Vector3f facing;
        float angle;

        static const math::Vector3f forward;

        math::Transform3 transform;
    }; // class Transformable
} // namespace system
} // namespace p2d