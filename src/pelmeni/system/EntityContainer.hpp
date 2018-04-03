#pragma once
#include <map>

#include "system/EngineDefs.hpp"
#include "utility/Pool.hpp"
#include "system/Entity.hpp"
#include "system/Transform.hpp"

namespace p2d { namespace system {
    class EntityContainer {
    public:
        Entity::id insertEntity(Entity&& movedEntity);
        void removeEntity(const Entity::id& entityId);

        Component::id insertTransform(Transform&& movedComponent);
        void removeTransform(const Component::id& componentId);
    private:
        utility::Pool<Entity, ENTITY_POOL_SIZE> entities;
        utility::Pool<Transform, ENTITY_POOL_SIZE> transforms;
        std::map<Entity::alias, Entity::id> aliasToIdMap;
    }; // class EntityContainer
} // namespace system
} // namespace p2ds