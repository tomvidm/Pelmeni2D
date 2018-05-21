#pragma once

#include <string>

#include "SFML/Graphics.hpp"

#include "system/Transformable2.hpp"

namespace p2d { namespace gui {
    struct TextStyle {
        sf::Color fillColor = sf::Color::Black;    

        unsigned charSize = 30;
        float lineSpacing = 1.f;
        float letterSpacing = 1.f;
    }; // struct TextStyle

    class Text : 
        public sf::Drawable,
        public system::Transformable2 {
    public:
        Text(const std::string& string, const sf::Font& font, const TextStyle& style);
    private:
        sf::Text sfmlText;
        TextStyle textStyle;
    }; // class Text
}
}