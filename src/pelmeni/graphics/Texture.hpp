#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    class Texture {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Texture>;

        Texture(const Texture::id& textureId, const std::string texturePath)
        : textureId(textureId) {
            sfmlTexture.loadFromFile(texturePath);
        }

        inline Texture::id getId() const { return textureId; }

    private:
        Texture::id textureId;

        sf::Texture sfmlTexture;
    }; // class Texture
} // namespace graphics
} // namespace p2d