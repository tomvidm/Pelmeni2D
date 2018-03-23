#include "gtest/gtest.h"

#include "pelmeni/graphics/Frame.hpp"
#include "pelmeni/graphics/FrameSequence.hpp"
#include "pelmeni/graphics/AnimationState.hpp"

class AnimationStateTest : public ::testing::Test {
public:
    void SetUp();

    p2d::graphics::AnimationState as;
    p2d::graphics::FrameSequence fseq;
}; // class AnimationStateTest