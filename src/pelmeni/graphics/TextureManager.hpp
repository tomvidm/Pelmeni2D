#pragma once

#include "graphics/Texture.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    class TextureManager {
        using TextureMap = utility::Map<Texture::id, sf::Texture>;
        using TextureLookupTable = utility::Map<Texture::id, std::string>;
    public:
        TextureManager() {
            initializeLookupTable();
        }

        sf::Texture& getTexture(const Texture::id& id);    
        void loadTexture(const Texture::id& id);
    private:
        void initializeLookupTable();
        TextureMap textureMap;
        TextureLookupTable textureLookupTable;
    }; // class TextureManager
} // namespace graphics
} // namespace p2d