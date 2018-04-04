#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::createEntity() {
        return entityContainer.insertEntity(Entity());
    }

    Entity::id EntityManager::createEntity(const Blueprint& blueprint) {
        
        return entityContainer.insertEntity(Entity());
    }

    void EntityManager::removeEntity(const Entity::id& entityId) {
        entityContainer.removeEntity(entityId);
    }
} // namespace system
} // namespace p2d