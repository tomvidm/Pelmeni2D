#pragma once

#include "SFML/Graphics.hpp"

#include "TextureLoader.hpp"
#include "../utility/ResourceManager.hpp"

namespace p2d { namespace graphics {
    using TextureManager = utility::ResourceManager<sf::Texture, TextureLoader>;
} // namespace graphics
} // namespace p2d