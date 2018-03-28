#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "graphics/Texture.hpp"

namespace p2d { namespace graphics {
    class TextureLoader {
    public:
        Texture::ptr createTexture(const Texture::id& textureId, const std::string& filepath);
    }; // class TextureLoader
} // namespace graphics
} // namespace p2d