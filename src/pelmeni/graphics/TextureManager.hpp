#pragma once

#include "SFML/Graphics.hpp"

#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "../utility/Map.hpp"

namespace p2d { namespace graphics {
    class TextureManager {
        using TexturePtrMap = utility::Map<TextureId, TexturePtr>;
    public:
        TexturePtr getTexture(const TextureId& id, const std::string& path = "");
        TexturePtr loadTexture(const TextureId& id, const std::string& path);
    private:
        TexturePtrMap texturePtrMap;
        TextureLoader textureLoader;
    }; // class TextureManager
} // namespace graphics
} // namespace p2d