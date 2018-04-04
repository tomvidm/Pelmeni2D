#pragma once

#include "system/EngineDefs.hpp"

#include "system/Blueprint.hpp"
#include "system/Entity.hpp"
#include "system/EntityContainer.hpp"
#include "system/Transform.hpp"
#include "system/ComponentPool.hpp"

namespace p2d { namespace system {
    class EntityManager {
    public:
        Entity::id createEntity();
        Entity::id createEntity(const Blueprint& blueprint);
        void removeEntity(const Entity::id& entityId);
    private:
        EntityContainer entityContainer;
        ComponentPool<Transform, COMPONENT_POOL_SIZE> transforms;
    }; // class EntityContainer
} // namespace system
} // namespace p2d