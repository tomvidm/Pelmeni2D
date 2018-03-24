#include "TextureLoader.hpp"

#include <iostream>

namespace p2d { namespace graphics {
    using ResourceId = std::string;
    
    std::pair<TextureId, TexturePtr> TextureLoader::load(const TextureId& id, const std::string& filepath) {
        std::cout << "TextureLoader::load(" << id << ", " << filepath << ")\n";
        const std::string resourceDirectory = "../resources/";
        const std::string fullpath = resourceDirectory + filepath;

        TexturePtr texturePtr = std::make_shared<sf::Texture>();
        std::cout << "TextureLoader::load: TexturePtr.get() = " << texturePtr.get() << "\n";  
        texturePtr->loadFromFile(fullpath);
        return std::make_pair(id, texturePtr);
    }
} // namespace graphics
} // namespace p2d