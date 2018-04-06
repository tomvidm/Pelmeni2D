#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::insertEntity(const Entity& entity) {
        entityContainer.push_back(entity);
        return entityContainer.size() - 1;
    }
} // namespace system
} // namespace p2d