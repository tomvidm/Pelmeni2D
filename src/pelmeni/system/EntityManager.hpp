#pragma once

#include "system/Blueprint.hpp"
#include "system/Entity.hpp"
#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    class EntityManager {
    public:
        Entity::id createEntity();
        Entity::id createEntity(const Blueprint::id& blueprintId);
        void removeEntity(const Entity::id& entityId);
    private:
        system::EntityContainer entityContainer;
    }; // class EntityContainer
} // namespace system
} // namespace p2d