#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    using TextureId = std::string;
    using TexturePtr = std::shared_ptr<sf::Texture>;

    TexturePtr loadTexture(const std::string& textureId, const std::string& texturePath);
} // namespace graphics
} // namespace p2d