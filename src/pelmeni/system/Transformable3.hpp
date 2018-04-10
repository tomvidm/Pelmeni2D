#pragma once

#include "math/Transform3.hpp"

namespace p2d { namespace system {
    class Transformable3 {
    public:
        Transformable3();
        void setPosition(const math::Vector3f& vec);
        void setOrigin(const math::Vector3f& vec);
        void setScale(const math::Vector3f& vec);
        math::Vector3f getPosition() const;
        math::Vector3f getOrigin() const;
        math::Vector3f getScale() const;
        
        math::Transform3 getTransform3();
    protected:
        bool needsUpdate;
        math::Vector3f position;
        math::Vector3f origin;
        math::Vector3f scale;

        math::Transform3 transform;
    }; // class Transformable
} // namespace system
} // namespace p2d