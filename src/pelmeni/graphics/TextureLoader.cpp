#include "TextureLoader.hpp"
#include "Texture.hpp"

namespace p2d { namespace graphics {
    Texture::ptr TextureLoader::createTexture(const Texture::id& textureId, const std::string& filepath) {
        return std::make_shared<Texture>(textureId, filepath);
    }
} // namespace graphics
} // namespace p2d