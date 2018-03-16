#include "gtest/gtest.h"

#include "SFML/System.hpp"
#include "pelmeni/input/MouseButtonState.hpp"

TEST(TestMouseButtonState, correctly_registers_click) {
    using p2d::input::MouseButtonState;
    using p2d::input::MouseButtonEventType;

    MouseButtonState mbState;

    mbState.press();
    sf::sleep(sf::milliseconds(150));
    EXPECT_TRUE(mbState.releaseWillRegisterAsClick());
    EXPECT_EQ(mbState.onReleaseEventType(), MouseButtonEventType::CLICK);
    
    sf::sleep(sf::milliseconds(150));
    EXPECT_FALSE(mbState.releaseWillRegisterAsClick());
    EXPECT_EQ(mbState.onReleaseEventType(), MouseButtonEventType::RELEASE);
}

TEST(TestMouseButtonState, correctly_registers_doubleclick) {
    using p2d::input::MouseButtonState;
    using p2d::input::MouseButtonEventType;

    MouseButtonState mbState;

    mbState.press();
    EXPECT_FALSE(mbState.pressWillRegisterAsDoubleClick());
    EXPECT_EQ(mbState.onPressEventType(), MouseButtonEventType::PRESS);
    sf::sleep(sf::milliseconds(50));

    mbState.release();
    sf::sleep(sf::milliseconds(50));
    EXPECT_TRUE(mbState.pressWillRegisterAsDoubleClick());
    EXPECT_EQ(mbState.onPressEventType(), MouseButtonEventType::DOUBLECLICK);
}