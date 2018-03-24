#include "selene.h"

#include "PackageLoader.hpp"

namespace p2d { namespace graphics {
    std::pair<PackageId, PackagePtr> PackageLoader::load(const PackageId& id) {
        sel::State luaState; 
        luaState.Load("../resources/packages/" + id + ".lua");
        sel::Selector selector = luaState["package"];

        TextureId textureId = selector["texture_id"];
        std::string texturePath = selector["texture_path"];
        TexturePtr texturePtr = textureManager.getTexture(textureId, texturePath);

        PackagePtr pkg;
        return std::pair<PackageId, PackagePtr>(id, pkg);
    } // loadResource
} // namespace graphics
} // namespace p2d