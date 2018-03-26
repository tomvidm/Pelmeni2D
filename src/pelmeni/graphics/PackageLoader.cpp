#include "selene.h"

#include "PackageLoader.hpp"

 #include "selene.h"
 #include <iostream>

namespace p2d { namespace graphics {
    Frame luaGetFrame(sel::Selector s) {
        int factor = s["T"];
        sf::Time duration = sf::milliseconds(factor);
        sf::Vector2i pos(s["x"], s["y"]);
        sf::Vector2i size(s["dx"], s["dy"]);
        sf::IntRect rect(pos, size);
        return Frame(duration, rect);
    }

    std::pair<AnimationId, FrameSequencePtr> luaGetFrameSequence(sel::Selector s) {
        FrameSequencePtr fSequencePtr = std::shared_ptr<FrameSequence>(new FrameSequence());
        int numFrames = s["num_frames"];
        AnimationId animId = s["animation_key"];
        for (int i = 1; i <= numFrames; i++) {
            Frame frame = luaGetFrame(s["frames"][i]);
            fSequencePtr->addFrame(frame);
        }
        
        return std::make_pair(animId, fSequencePtr);
    }

    AnimationPtrMap luaGetFrameSequences(sel::Selector s) {
        AnimationPtrMap animationPtrMap;
        int numFrameSequences = s["num_frame_sequences"];
        s = s["frame_sequences"];
        for (int i = 1; i <= numFrameSequences; i++) {
            animationPtrMap.insert(luaGetFrameSequence(s[i]));
        }
        return animationPtrMap;
    }

    std::pair<PackageId, PackagePtr> PackageLoader::load(const PackageId& id) {
         
        sel::State luaState{true}; 
        luaState.Load("../resources/packages/" + id + ".lua");
        sel::Selector selector = luaState["package"];

        TextureId textureId = selector["texture_id"];
        std::string texturePath = selector["texture_path"];
        int numFrameSequences = selector["num_frame_sequences"];

        TexturePtr texturePtr = textureManager.getTexture(textureId, texturePath);
        AnimationPtrMap animationPtrMap = luaGetFrameSequences(selector);
        PackagePtr pkg = std::make_shared<Package>(texturePtr, animationPtrMap);
        return std::pair<PackageId, PackagePtr>(id, pkg);
    } // loadResource
} // namespace graphics
} // namespace p2d