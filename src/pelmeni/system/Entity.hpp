#pragma once

#include <memory>
#include <string>

#include "system/Component.hpp"

namespace p2d { namespace system {
    class Entity {
    public:
        using id = unsigned;
        using alias = std::string;
        using shared = std::shared_ptr<Entity>;
        using unique = std::unique_ptr<Entity>;

        Entity();
        Entity(const Entity::id& newId);
        Entity(const Entity::id& newId, const Entity::alias& newAlias);
        Entity(const Entity& copy);
        Entity(Entity&& other);

        inline Entity::id getId() const { return entityId; }
        inline Entity::alias getAlias() const { return entityAlias; }

        void update();
    protected:
        Entity::id entityId;
        Entity::alias entityAlias;
    }; // class Object
} // namespace system
} // namespace p2d