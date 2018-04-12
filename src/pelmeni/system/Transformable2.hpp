#pragma once


#include "math/Radian.hpp"
#include "math/Transform.hpp"

namespace p2d { namespace system {
    class Transformable2 {
    public:
        Transformable2(const math::Vector2f& initialPosition,
                       const math::Vector2f& initialOrigin,
                       const math::Vector2f& initialScale,
                       const math::Radian& initialRotation);

        Transformable2();
        
        Transformable2(const math::Vector2f& initialPosition);

        void setPosition(const math::Vector2f& vec);
        void setOrigin(const math::Vector2f& vec);
        void setScale(const math::Vector2f& vec);
        void setRotation(const math::Radian& rads);
        math::Vector2f getPosition() const;
        math::Vector2f getOrigin() const;
        math::Vector2f getScale() const;
        math::Radian getRotation() const;

        void move(const math::Vector2f& vec);
        void rotate(const math::Radian& rads);
        
        math::Transform getTransform();
    protected:
        bool needsUpdate;
        math::Vector2f position;
        math::Vector2f origin;
        math::Vector2f scale;
        math::Radian rotation;
        
        math::Transform transform;

    }; // class Transformable
} // namespace system
} // namespace p2d