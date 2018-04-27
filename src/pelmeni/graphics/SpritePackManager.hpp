#pragma once

#include <string>
#include <map>
#include <memory>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "graphics/TextureManager.hpp"
#include "graphics/SpritePack.hpp"
#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    class SpritePackManager {
        using SpritePackMap = std::map<SpritePack::alias, SpritePack::shared>;
    public:
        SpritePack::shared get(const SpritePack::alias& spritePackAlias);
        void loadSpritePacksFromList(const std::string& spritePackList, TextureManager* textureManager);
        void listResources() const;
    private:
        void loadSpritePackFromListing(rapidjson::Value& spritePackListing, TextureManager* textureManager);
        utility::Map<FrameSequence::id, FrameSequence> loadFrameSequences(rapidjson::Value& frameSequences);
        FrameSequence loadSingleFrameSequence(rapidjson::Value& entry);
        SpritePackMap spritePackMap;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d