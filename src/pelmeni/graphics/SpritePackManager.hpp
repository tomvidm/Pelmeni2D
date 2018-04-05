#pragma once

#include <string>
#include <memory>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "utility/Map.hpp"
#include "graphics/SpritePack.hpp"

namespace p2d { namespace graphics {
    class SpritePackManager {
        using SpritePackMap = utility::Map<SpritePack::alias, SpritePack::shared>;
    public:
        void loadSpritePacksFromList(const std::string& spritePackList);
    private:
        void loadSpritePackFromListing(rapidjson::Value& spritePackListing);
        
        SpritePackMap spritePackMap;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d