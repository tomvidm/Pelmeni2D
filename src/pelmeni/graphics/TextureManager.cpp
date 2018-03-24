#include "TextureManager.hpp"

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
        texturePtrMap.insert(textureLoader.load(id, path));
        return texturePtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d