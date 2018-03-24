#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    using TextureId = std::string;
    using Texture = sf::Texture;
    using TexturePtr = std::shared_ptr<sf::Texture>;
} // namespace graphics
} // namespace p2d