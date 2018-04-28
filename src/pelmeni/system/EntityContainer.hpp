#pragma once
#include <map>

#include "system/EngineDefs.hpp"
#include "utility/Pool.hpp"
#include "system/Entity.hpp"

namespace p2d { namespace system {
    class EntityContainer {
    public:
        Entity::id insertEntity(const Entity& entity);
        void removeEntity(const Entity::id& entityId);
    private:
        utility::Pool<Entity, ENTITY_POOL_SIZE> entities;
    }; // class EntityContainer
} // namespace system
} // namespace p2ds