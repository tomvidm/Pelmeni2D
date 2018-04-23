#include "gtest/gtest.h"

#include "SFML/System.hpp"
#include "input/MouseState.hpp"
#include "input/MouseButtonEvent.hpp"

TEST(TestMouseState, correctly_registers_click_and_double_click) {
    using p2d::input::MouseState;
    using p2d::input::MouseButton;
    using p2d::input::MouseButtonEvent;
    using p2d::input::MouseButtonEventType;
    using p2d::input::MouseButtonSecondaryEventType;

    MouseState mState;
    MouseButtonEvent mbEvent;
    MouseButtonEvent expected_mbLeftPressEvent = {
        MouseButton::LEFT,
        MouseButtonEventType::PRESS
    };

    MouseButtonEvent expected_mbLeftDoubleClickEvent = {
        MouseButton::LEFT,
        MouseButtonEventType::PRESS,
        MouseButtonSecondaryEventType::DOUBLECLICK
    };
    
    MouseButtonEvent expected_mbLeftClickEvent = {
        MouseButton::LEFT,
        MouseButtonEventType::RELEASE,
        MouseButtonSecondaryEventType::CLICK
    };
    
    sf::sleep(sf::milliseconds(200));
    mbEvent = mState.onMouseButtonEvent(sf::Event::EventType::MouseButtonPressed, MouseButton::LEFT);
    EXPECT_EQ(expected_mbLeftPressEvent.eventType, mbEvent.eventType);

    sf::sleep(sf::milliseconds(50));
    mbEvent = mState.onMouseButtonEvent(sf::Event::EventType::MouseButtonReleased, MouseButton::LEFT);
    EXPECT_EQ(expected_mbLeftClickEvent.eventType, mbEvent.eventType);

    sf::sleep(sf::milliseconds(50));
    mState.onMouseButtonEvent(sf::Event::EventType::MouseButtonPressed, MouseButton::LEFT);
    sf::sleep(sf::milliseconds(50));
    mState.onMouseButtonEvent(sf::Event::EventType::MouseButtonReleased, MouseButton::LEFT);
    sf::sleep(sf::milliseconds(50));
    mbEvent = mState.onMouseButtonEvent(sf::Event::EventType::MouseButtonPressed, MouseButton::LEFT);
    EXPECT_EQ(expected_mbLeftDoubleClickEvent.eventType, mbEvent.eventType);
}