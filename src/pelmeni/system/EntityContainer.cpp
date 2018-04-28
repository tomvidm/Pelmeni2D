#include <cstdio>

#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    Entity::id EntityContainer::insertEntity(const Entity& entity) {
        Entity::id entityId = entities.push(entity);
        return entityId;
    }

    Entity& EntityContainer::getEntity(const Entity::id entityId) {
        return entities.get(entityId);
    }

    void EntityContainer::removeEntity(const Entity::id& entityId) {
        entities.remove(entityId);
    }
} // namespace system
} // namespace p2d