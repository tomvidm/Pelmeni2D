#pragma once

#include "graphics/Texture.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    class TextureManager {
        using TextureMap = utility::Map<Texture::id, sf::Texture>;
    public:
        void loadTexturesFromList(const std::string& textureList);
        void loadTextureFromListing(rapidjson::Value& textureListing);    
    private:
        TextureMap textureMap;
    }; // class TextureManager
} // namespace graphics
} // namespace p2d