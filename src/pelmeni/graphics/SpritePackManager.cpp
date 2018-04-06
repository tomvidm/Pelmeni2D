#include "json/Helpers.hpp"

#include "SpritePackManager.hpp"

namespace p2d { namespace graphics {
    SpritePack::shared SpritePackManager::get(const SpritePack::alias& spritePackAlias) {
        return spritePackMap.get(spritePackAlias);
    }

    void SpritePackManager::loadSpritePacksFromList(const std::string& spritePackListPath, TextureManager* textureManager) {
        printf("Fetching sprite packs from %s...\n", spritePackListPath.c_str());

        rapidjson::Document doc = json::parseJsonFile("../resources/" + spritePackListPath);

        for (auto& entry : doc.GetArray()) {
            loadSpritePackFromListing(entry, textureManager);
        }
    }

    void SpritePackManager::loadSpritePackFromListing(rapidjson::Value& spritePackListing, TextureManager* textureManager) {
        std::string spritePackAlias = spritePackListing["spritepack_alias"].GetString();
        std::string textureAlias = spritePackListing["texture_alias"].GetString();
        printf("  Loading SpritePack %s\n", spritePackAlias.c_str());

        SpritePack::shared spritePack = std::make_shared<SpritePack>();
        spritePack->texture = textureManager->get(textureAlias);
        printf("loadSpritePackFromListing::spritePack.get() = %p\n", spritePack.get());

        // TODO
        spritePackMap.insert(spritePackAlias, spritePack);
    }
} // namespace graphics
} // namespace p2d