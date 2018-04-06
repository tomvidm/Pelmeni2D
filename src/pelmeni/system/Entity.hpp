#pragma once

#include <memory>
#include <string>

#include "system/EngineDefs.hpp"

#include "graphics/Sprite.hpp"

#include "system/Component.hpp"
#include "system/EntityState.hpp"
#include "system/Transform.hpp"

namespace p2d { namespace system {
    class Entity {
    public:
        using id = system::IdType;
        using alias = std::string;
        using shared = std::shared_ptr<Entity>;
        using unique = std::unique_ptr<Entity>;

        Entity();
        Entity(const graphics::SpritePack::shared spritePack, const EntityState& initialState);
        Entity(const Entity& copy);
        Entity(Entity&& other);
        Entity operator = (const Entity& other);

        inline void setTransform(const Transform& transformArg) { transform = transformArg; }

        inline Transform getTransform() const { return transform; }
        inline graphics::Sprite& getSprite() { return sprite; } 

        void update(const sf::Time& dt);
    protected:        
        system::Transform transform;
        graphics::Sprite sprite;
    }; // class Object
} // namespace system
} // namespace p2d