#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    Entity::id EntityManager::insertEntity(const Entity::alias& alias, const Entity& entity) {
        const Entity::id id = entityContainer.size() - 1; 
        entityContainer.push_back(entity);
        if (!alias.empty()) {
            entityIdToIndexMap.insert(std::make_pair(alias, id));
        }
        return id;
    }

    Entity& EntityManager::get(const Entity::id id) {
        return entityContainer.at(id);
    }

    Entity& EntityManager::get(const Entity::alias alias) {
        const Entity::id id = entityIdToIndexMap.at(alias);
        return entityContainer.at(id);
    }
} // namespace system
} // namespace p2d