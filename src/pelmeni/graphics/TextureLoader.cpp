#include "TextureLoader.hpp"

namespace p2d { namespace graphics {
    using ResourceId = std::string;
    
    std::pair<ResourceId, TexturePtr> TextureLoader::load(const TextureId& id, const std::string& filepath) {
        const std::string resourceDirectory = "../resources/";
        const std::string fullpath = resourceDirectory + filepath;

        sf::Texture texture;
        texture.loadFromFile(fullpath);
        return std::pair<ResourceId, TexturePtr>(id, std::make_shared<sf::Texture>(texture));
    }
} // namespace graphics
} // namespace p2d