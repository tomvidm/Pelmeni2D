#pragma once

#include "graphics/Texture.hpp"
//#include "graphics/TextureLoader.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    class TextureManager {
        using TextureMap = utility::Map<Texture::id, Texture::ptr>;
        using TextureLookupTable = utility::Map<Texture::id, std::string>;
    public:
        TextureManager() {
            initializeLookupTable();
        }

        Texture::ptr getTexture(const Texture::id& id);    
        void loadTexture(const Texture::id& id);
    private:
        void initializeLookupTable();
        TextureMap textureMap;
        TextureLookupTable textureLookupTable;
        //TextureLoader textureLoader;
    }; // class TextureManager
} // namespace graphics
} // namespace p2d