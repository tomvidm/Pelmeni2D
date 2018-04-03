#pragma once

#include "math/vector.hpp"
#include "system/Component.hpp"

namespace p2d { namespace system {
    class Transform : system::Component {
    public:
        using id = unsigned;
        Transform() : Component(Component::type::transform) {;}
        Transform(Transform&& other) : Component(Component::type::transform) { position = std::move(other.position); }
        
        math::Vector2f getPosition() const { return position; }

        virtual void update() {;}
    protected:
        math::Vector2f position;
    }; // class Transform
} // namespace system
} // namespace p2d