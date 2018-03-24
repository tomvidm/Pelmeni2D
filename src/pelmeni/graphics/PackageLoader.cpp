#include "selene.h"

#include "PackageLoader.hpp"

 #include "selene.h"

namespace p2d { namespace graphics {
    Frame luaGetFrame(sel::Selector& s) {
        float factor = s["T"];
        sf::Time duration = sf::milliseconds(static_cast<int>(factor * 50));
        sf::Vector2i pos(s["x"], s["y"]);
        sf::Vector2i size(s["dx"], s["dy"]);
        sf::IntRect rect(pos, size);
        return Frame(duration, rect);
    }

    std::pair<AnimationId, FrameSequence> luaGetFrameSequence(sel::Selector& s) {
        FrameSequence fSequence;
        size_t numFrames = s["num_frames"];
        AnimationId animId = s["animation_key"];
        for (size_t i = 0; i < numFrames; i++) {
            fSequence.addFrame(s[i]);
        }
    }

    std::pair<PackageId, PackagePtr> PackageLoader::load(const PackageId& id) {
         
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