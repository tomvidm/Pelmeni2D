#include <cstdio>

#include "Entity.hpp"

namespace p2d { namespace system {
    Entity::Entity() {
        ;
    }

    Entity::Entity(const Entity& copy)
    : entityId(copy.getId()), entityAlias(copy.getAlias()) {
        ;
    }

    Entity::Entity(Entity&& other) 
    : entityId(std::move(other.entityId)), entityAlias(std::move(other.entityAlias)) {
        ;
    }

    Entity& Entity::operator = (Entity&& other) {
        entityAlias = other.getAlias();
        return *this;
    }

    void Entity::update() {
        ;
    }
} // namespace system
} // namespace p2d