#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    using Texture = sf::Texture;
    using TextureId = std::string;
    using TexturePtr = std::shared_ptr<sf::Texture>;

    class TextureLoader {
    public:
        std::pair<TextureId, TexturePtr> load(const TextureId& id, const std::string& filepath);
    }; // class TextureLoader
} // namespace graphics
} // namespace p2d