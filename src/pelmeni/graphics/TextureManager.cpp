#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    TexturePtr TextureManager::getTexture(const TextureId& id, const std::string& path) {
        std::cout << "TextureManager::getTexture(" << id << ", " << path << ")\n";
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
        std::cout << "TextureManager::loadTexture(" << id << ", " << path << ")\n";
        std::pair<TextureId, TexturePtr> keyValuePair = textureLoader.load(id, path);
        texturePtrMap.insert(keyValuePair);
        return texturePtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d