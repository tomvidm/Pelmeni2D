#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    void EntityContainer::insert(const Entity::id entityId, Entity& movedEntity) {
        entityMap.insert(std::make_pair(entityId, std::move(movedEntity)));
    }

    void EntityContainer::insertAliasMapping(const Entity::alias newAlias, const Entity::id& newId) {
        aliasToIdMap.insert(std::make_pair(newAlias, newId));
    }
} // namespace system
} // namespace p2d