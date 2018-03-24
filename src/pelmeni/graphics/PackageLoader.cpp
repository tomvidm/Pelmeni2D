#include "selene.h"

#include "PackageLoader.hpp"

#include <iostream>

namespace p2d { namespace graphics {
    std::pair<PackageId, PackagePtr> PackageLoader::load(const PackageId& id) {
        std::cout << "PackageLoader::load(" << id << ")\n";
        sel::State luaState{true}; 
        luaState.Load("../resources/packages/" + id + ".lua");
        sel::Selector selector = luaState["package"];

        TextureId textureId = selector["texture_id"];
        std::string texturePath = selector["texture_path"];
        int numFrameSequences = selector["num_frame_sequences"];

        TexturePtr texturePtr = textureManager.getTexture(textureId, texturePath);

        PackagePtr pkg = std::make_shared<Package>(texturePtr);
        return std::pair<PackageId, PackagePtr>(id, pkg);
    } // loadResource
} // namespace graphics
} // namespace p2d