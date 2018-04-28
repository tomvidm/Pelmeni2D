#pragma once

#include "graphics/SpriteBase.hpp"
#include "graphics/SpritePack.hpp"
#include "graphics/AnimationState.hpp"
#include "animation/Animable.hpp"

namespace p2d { namespace graphics {
    class AnimatedSprite
    : public graphics::SpriteBase,
      public animation::Animable {
    public:
        using id = system::IdType;
        using shared = std::shared_ptr<AnimatedSprite>;
        using unique = std::unique_ptr<AnimatedSprite>;

        AnimatedSprite();
        AnimatedSprite(const AnimatedSprite& other);

        AnimatedSprite operator = (const AnimatedSprite& other);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void setSpritePack(const SpritePack::shared spritePack);
        void setSpriteAnimation(const FrameSequence::alias& animationAlias);

        void update(const sf::Time& dt);
    protected:
        bool isDrawable = false;
        AnimationState _animationState;
        SpritePack::shared _spritePack;
    }; // class AnimatedSprite
} // namespace graphics
} // namespace p2d 