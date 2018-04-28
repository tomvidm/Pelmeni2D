#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "math/Vector.hpp"
#include "system/EngineDefs.hpp"

namespace p2d { namespace graphics {
    class SpriteBase
    : public sf::Drawable {
    public:
        using id = system::IdType;
        using shared = std::shared_ptr<SpriteBase>;
        using unique = std::unique_ptr<SpriteBase>;

        SpriteBase();
        SpriteBase(const SpriteBase& other);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void setTextureRect(const sf::Rect<float>& rect);
        void setTexture(sf::Texture& texture);

    protected:
        sf::Vertex _vertices[4];
        sf::Texture* _texturePtr;
    }; // class SpriteBase
} // namespace graphics
} // namespace p2d