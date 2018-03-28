#include <cstdio>
#include <cassert>
#include <string>

#include "json/Helpers.hpp"

#include "FrameSequenceLoader.hpp"

namespace p2d { namespace graphics {
    FrameSequence::ptr FrameSequenceLoader::generateFrameSequence(const FrameSequence::id& fSequenceId, rapidjson::Value& jsonEntry) {
        printf("\tGenerating FrameSequence with id %s\n", fSequenceId.c_str());
        FrameSequence::ptr fSequence = std::make_shared<FrameSequence>();
        assert(jsonEntry["frames"].IsArray() == true);
        
        for (auto& frame : jsonEntry["frames"].GetArray()) {
            const sf::Time framePeriod = sf::milliseconds(frame[0].GetInt());
            const int x = frame[1].GetInt();
            const int y = frame[2].GetInt();
            const int xsize = frame[3].GetInt();
            const int ysize = frame[4].GetInt();
            fSequence->addFrame(Frame(framePeriod, x, y, xsize, ysize));
        }

        return fSequence;
    }
} // namespace graphics
} // namespace p2d