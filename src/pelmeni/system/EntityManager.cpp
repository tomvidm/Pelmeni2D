#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::createEntity() {
        return entityContainer.insertEntity(Entity());
    }

    Entity::id EntityManager::createEntity(const Blueprint::id& blueprintId) {
        /*
            use blueprint data to construct an entity and initialize its values
        */
        return entityContainer.insertEntity(Entity());
    }

    void EntityManager::removeEntity(const Entity::id& entityId) {
        entityContainer.removeEntity(entityId);
    }
} // namespace system
} // namespace p2d