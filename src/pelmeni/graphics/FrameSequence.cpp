#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
    void FrameSequence::addFrame(const Frame& frame) {
        sequence.push_back(frame);
    }

    Frame& FrameSequence::operator [] (const unsigned& index) {
        return sequence.at(index);
    }
} // namespace graphics
} // namespace p2d