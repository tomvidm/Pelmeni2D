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

        if (spritePackListing["is_animated"].GetBool()) {
            spritePack->frameSequenceMap = loadFrameSequences(spritePackListing["animations"]);
        }

        spritePackMap.insert(spritePackAlias, spritePack);
    }

    utility::Map<FrameSequence::id, FrameSequence> SpritePackManager::loadFrameSequences(rapidjson::Value& frameSequences) {
        utility::Map<FrameSequence::id, FrameSequence> fSequenceMap;
        for (auto& entry : frameSequences.GetArray()) {
            const FrameSequence::id fSequenceId = entry["animation_key"].GetString();
            printf("    Loading frame sequence %s\n", fSequenceId.c_str());
            fSequenceMap.insert(fSequenceId, loadSingleFrameSequence(entry));
        }
        return fSequenceMap;
    }

    FrameSequence SpritePackManager::loadSingleFrameSequence(rapidjson::Value& entry) {
        FrameSequence fSequence;
        for (auto& frame : entry["frames"].GetArray()) {
            fSequence.addFrame(Frame(
                sf::milliseconds(frame[0].GetInt()),
                frame[1].GetInt(),
                frame[2].GetInt(),
                frame[3].GetInt(),
                frame[4].GetInt()
            ));
        }
        return fSequence;
    }
} // namespace graphics
} // namespace p2d