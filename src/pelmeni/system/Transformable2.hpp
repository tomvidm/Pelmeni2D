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
        void setRotation(const math::Vector2f& direction);
        math::Vector2f getPosition() const;
        math::Vector2f getOrigin() const;
        math::Vector2f getScale() const;
        math::Radian getRotation() const;

        void move(const math::Vector2f& vec);
        void rotate(const math::Radian& rads);

        inline bool needsUpdate() const { return _needsUpdate; }
  
        math::Transform getLocalTransform() const;
        math::Transform getRelativeTransform(const math::Transform& relTransform) const;
        math::Transform getInverseLocalTransform() const;
    protected:
        mutable bool _needsUpdate;
        math::Vector2f position;
        math::Vector2f origin;
        math::Vector2f scale;
        math::Radian rotation;
        
        mutable math::Transform localTransform;
        mutable math::Transform inverseLocalTransform;
    }; // class Transformable
} // namespace system
} // namespace p2d