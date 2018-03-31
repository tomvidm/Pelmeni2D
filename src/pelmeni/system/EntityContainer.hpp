#pragma once

#include <map>
#include <unordered_map>

#include "system/Entity.hpp"

namespace p2d { namespace system {
    class EntityContainer {
    public:
        void insert(const Entity::id entityId, Entity& movedEntity);
        void insertAliasMapping(const Entity::alias newAlias, const Entity::id& newId);
    private:
        std::unordered_map<Entity::id, Entity> entityMap;
        std::map<Entity::alias, Entity::id> aliasToIdMap;
    }; // class EntityContainer
} // namespace system
} // namespace p2ds