#include "TextureManager.hpp"

#include "Sprite.hpp"

namespace p2d { namespace graphics {
    TexturePtr TextureManager::getTexture(const TextureId& id, const std::string& path) {
         
        if (!texturePtrMap.contains(id)) {
            if (path.empty()) {
                return TexturePtr();
            } else {
                return loadTexture(id, path);
            }
        } else {
            return texturePtrMap.get(id);
        } // if else
    } // loadPackage

    TexturePtr TextureManager::loadTexture(const TextureId& id, const std::string& path) {
         
        std::pair<TextureId, TexturePtr> keyValuePair = textureLoader.load(id, path);
        Sprite sprite;
        sprite.useTexture(keyValuePair.second);
        texturePtrMap.insert(keyValuePair);
        return keyValuePair.second;
    }
} // namespace graphics
} // namespace p2d