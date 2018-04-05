#include <cstdio>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    Texture& TextureManager::get(const Texture::id& textureId) {
        return textureMap.get(textureId);
    }

    void TextureManager::loadTexturesFromList(const std::string& textureList) {
        printf("Fetching textures from %s...\n", textureList.c_str());
        rapidjson::Document doc = json::parseJsonFile("../resources/" + textureList);

        for (auto& entry : doc.GetArray()) {
            loadTextureFromListing(entry);
        }
    }

    void TextureManager::loadTextureFromListing(rapidjson::Value& textureListing) {
        graphics::Texture::id textureId = textureListing[0].GetString();
        graphics::Texture::file texturePath = textureListing[1].GetString();
        
        printf("  Loaded texture %s from %s\n", textureId.c_str(), texturePath.c_str());
        textureMap.insert(textureId, Texture(texturePath));
    }
} // namespace graphics
} // namespace p2d