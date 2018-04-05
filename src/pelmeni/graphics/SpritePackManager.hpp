#pragma once

#include <string>
#include <memory>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "utility/Map.hpp"
#include "graphics/TextureManager.hpp"
#include "graphics/SpritePack.hpp"

namespace p2d { namespace graphics {
    class SpritePackManager {
        using SpritePackMap = utility::Map<SpritePack::alias, SpritePack::shared>;
    public:
        void loadSpritePacksFromList(const std::string& spritePackList, TextureManager* textureManager);
    private:
        void loadSpritePackFromListing(rapidjson::Value& spritePackListing, TextureManager* textureManager);
        
        SpritePackMap spritePackMap;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d