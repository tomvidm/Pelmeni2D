#include "json/Helpers.hpp"

#include "SpritePackManager.hpp"

namespace p2d { namespace graphics {
    void SpritePackManager::loadSpritePacksFromList(const std::string& spritePackListPath) {
        printf("Fetching sprite packs from %s...\n", spritePackListPath.c_str());

        rapidjson::Document doc = json::parseJsonFile("../resources/" + spritePackListPath);

        for (auto& entry : doc.GetArray()) {
            loadSpritePackFromListing(entry);
        }
    }

    void SpritePackManager::loadSpritePackFromListing(rapidjson::Value& spritePackListing) {
        std::string spritePackAlias = spritePackListing["spritepack_alias"].GetString();
        printf("  Loading SpritePack %s\n", spritePackAlias.c_str());

        // TODO
        spritePackMap.insert(spritePackAlias, std::make_shared<SpritePack>(SpritePack()));
    }
} // namespace graphics
} // namespace p2d