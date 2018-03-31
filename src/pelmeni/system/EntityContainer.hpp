#pragma once
#include <map>

#include "system/EngineDefs.hpp"
#include "utility/Pool.hpp"
#include "system/Entity.hpp"

namespace p2d { namespace system {
    class EntityContainer {
    public:
        Entity::id insert(Entity&& movedEntity);
    private:
        utility::Pool<Entity, ENTITY_POOL_SIZE> entities;
        std::map<Entity::alias, Entity::id> aliasToIdMap;
    }; // class EntityContainer
} // namespace system
} // namespace p2ds