#include <cstdio>

#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    Entity::id EntityContainer::insertEntity(Entity&& entity) {
        Entity::id entityId = entities.push(std::move(entity));
        return entityId;
    }

    void EntityContainer::removeEntity(const Entity::id& entityId) {
        entities.remove(entityId);
    }
} // namespace system
} // namespace p2d