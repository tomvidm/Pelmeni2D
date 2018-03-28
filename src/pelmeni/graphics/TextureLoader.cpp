#include "TextureLoader.hpp"
#include "Texture.hpp"

namespace p2d { namespace graphics {
    Texture::ptr TextureLoader::createTexture(const Texture::id& textureId, const std::string& filepath) {
        printf("TextureLoader: Creating Texture from file %s\n", filepath.c_str());
        return std::make_shared<Texture>(textureId, filepath);
    }
} // namespace graphics
} // namespace p2d