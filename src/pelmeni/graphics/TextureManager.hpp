#pragma once

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "graphics/Texture.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    class TextureManager {
        using TextureMap = utility::Map<Texture::id, Texture>;
    public:
        Texture& get(const Texture::id& textureId);
        void loadTexturesFromList(const std::string& textureList);
    private:
        void loadTextureFromListing(rapidjson::Value& textureListing); 

        TextureMap textureMap;
    }; // class TextureManager
} // namespace graphics
} // namespace p2d