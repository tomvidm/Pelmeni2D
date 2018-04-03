#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::createEntity() {
        return entityContainer.insert(Entity());
    }

    Entity::id EntityManager::createEntity(const Blueprint::id& blueprintId) {
        /*
            use blueprint data to construct an entity and initialize its values
        */
        return entityContainer.insert(Entity());
    }

    void EntityManager::removeEntity(const Entity::id& entityId) {
        entityContainer.remove(entityId);
    }
} // namespace system
} // namespace p2d