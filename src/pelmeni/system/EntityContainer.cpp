#include <cstdio>

#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    Entity::id EntityContainer::insert(Entity&& entity) {
        Entity::id entityId = entities.push(std::move(entity));
        printf("Entity inserted with id %zu\n", entityId);
        return entityId;
    }
} // namespace system
} // namespace p2d