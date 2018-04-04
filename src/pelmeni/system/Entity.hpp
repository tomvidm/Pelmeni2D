#pragma once

#include <memory>
#include <string>

#include "graphics/Sprite.hpp"

#include "system/Component.hpp"
#include "system/Transform.hpp"

namespace p2d { namespace system {
    class Entity {
    public:
        using id = unsigned;
        using alias = std::string;
        using shared = std::shared_ptr<Entity>;
        using unique = std::unique_ptr<Entity>;

        Entity();
        Entity(const Entity& copy);
        Entity(Entity&& other);
        Entity& operator = (Entity&& other);

        inline Entity::id getId() const { return entityId; }
        inline Entity::alias getAlias() const { return entityAlias; }
        inline Transform getTransform() const { return transform; }

        void update();
    protected:
        Entity::id entityId;
        Entity::alias entityAlias;
        
        system::Transform transform;
        graphics::Sprite sprite;
    }; // class Object
} // namespace system
} // namespace p2d