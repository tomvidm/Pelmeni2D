#include <cstdio>

#include "Entity.hpp"

namespace p2d { namespace system {
    Entity::Entity() {
        ;
    }

    Entity::Entity(const graphics::SpritePack::shared spritePack) {
        sprite.setSpritePack(spritePack);
    }

    Entity::Entity(const Entity& copy)
    : transform(copy.transform),
      sprite(copy.sprite) {
        ;
    }

    Entity::Entity(Entity&& other) 
    : transform(std::move(other.transform)),
      sprite(std::move(other.sprite)) {
        ;
    }

    Entity Entity::operator = (const Entity& other) {
        transform = other.transform;
        sprite = other.sprite;
        return *this;
    }

    void Entity::update(const sf::Time& dt) {
        sprite.update(dt);
    }
} // namespace system
} // namespace p2d