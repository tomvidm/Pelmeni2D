#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "graphics/SpritePack.hpp"
#include "graphics/AnimationState.hpp"

#include "system/Transformable2.hpp"
#include "system/EngineDefs.hpp"

namespace p2d { namespace graphics {
    class Sprite
    : public sf::Drawable,
      public system::Transformable2 {
    public:
        using id = system::IdType;
        using shared = std::shared_ptr<Sprite>;
        using unique = std::unique_ptr<Sprite>;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void setSpritePack(const SpritePack::shared spritePack);
        void setAnimation(const FrameSequence::alias& animationAlias);
        void setTextureRect(const sf::Rect<float>& rect);

        void update(const sf::Time& dt);
        AnimationState _animationState;
    private:
        bool isDrawable = false;
        SpritePack::shared _spritePack;
        sf::Vertex _vertices[4];
        sf::Texture* _texturePtr;
    }; // class Sprite
} // namespace graphics
} // namespace p2d