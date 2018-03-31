#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::createEntity() {
        return entityContainer.insert(Entity());
    }
} // namespace system
} // namespace p2d