#pragma once

#include <string>
#include <memory>

#include "Frame.hpp"

namespace p2d { namespace graphics {
    class FrameSequence {
    public:
        using id = std::string;
        using alias = std::string;
        using ptr = std::shared_ptr<FrameSequence>;
        

        void addFrame(const Frame& frame);
        inline size_t getNumFrames() const { return sequence.size(); }
        Frame& operator [] (const unsigned& index);
    private:
        std::vector<Frame> sequence;
    }; // class Frame
} // namespace graphics
} // namespace p2d