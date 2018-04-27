#include <cstdio>

#include "Entity.hpp"

namespace p2d { namespace system {
    Entity::Entity() {
        ;
    }

    Entity::Entity(const graphics::SpritePack::shared spritePack, const EntityState& initialState)
    {
        sprite.setSpritePack(spritePack);
        sprite.setPosition(initialState.position);
        sprite.setScale(initialState.scale);
        sprite.setRotation(initialState.rotation);
        sprite.setAnimation("default");
    }

    Entity::Entity(const Entity& copy)
    : sprite(copy.sprite) {
        ;
    }

    Entity::Entity(Entity&& other) 
    : sprite(std::move(other.sprite)) {
        ;
    }

    Entity Entity::operator = (const Entity& other) {
        sprite = other.sprite;
        return *this;
    }

    void Entity::onEvent(const input::InputEvent& event) {
        ;
    }

    void Entity::update(const sf::Time& dt) {
        sprite.update(dt);
    }
} // namespace system
} // namespace p2d