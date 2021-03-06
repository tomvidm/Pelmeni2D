#pragma once

#include <memory>
#include <string>

#include "system/EngineDefs.hpp"

#include "graphics/AnimatedSprite.hpp"

#include "input/InputListener.hpp"
#include "system/EntityState.hpp"
#include "math/Transform3.hpp"

namespace p2d { namespace system {
    class Entity
    : public input::InputListener {
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

        virtual void onEvent(const input::InputEvent& event);

        inline graphics::AnimatedSprite& getSprite() { return sprite; } 
        inline const graphics::AnimatedSprite& getSprite() const { return sprite; } 

        void update(const sf::Time& dt);
    protected:        
        graphics::AnimatedSprite sprite;
    }; // class Object
} // namespace system
} // namespace p2d