#pragma once

#include <string>

#include "Frame.hpp"

namespace p2d { namespace graphics {
    class FrameSequence {
    public:
        using is = std::string;

        void addFrame(const Frame& frame);
        inline size_t getNumFrames() const { return sequence.size(); }
        Frame& operator [] (const unsigned& index);
    private:
        std::vector<Frame> sequence;
    }; // class Frame
} // namespace graphics
} // namespace p2d