#include <iostream>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <tuple>


#include "SFML/Graphics.hpp"

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"

#include "input/InputManager.hpp"
#include "graphics/Tilemap.hpp"
#include "math/graph/TilemapGraph.hpp"
#include "experimental/TilemapWIP.hpp"
#include "gui/Widget.hpp"
#include "gui/WidgetManager.hpp"
#include "system/Scene.hpp"

float randf() {
    const float r = static_cast<float>(rand());
    const float r_max = static_cast<float>(RAND_MAX);
    return r / r_max;
}

int main() {
    using namespace p2d;
    const size_t rows = 155;
    const size_t cols = 155;

    srand(time(NULL));
    gui::WidgetManager wm;
    wm.createWidget(gui::WidgetType::BaseWidget);
    wm.createWidget(gui::WidgetType::BaseWidget);

    sf::RenderWindow window(sf::VideoMode(800, 600), "main.cpp");
    sf::Clock timer;
    sf::Event event;
    input::InputManager inputManager;

    inputManager.registerListener(input::InputEventType::MOUSEMOVE, &wm);
    inputManager.registerListener(input::InputEventType::MOUSEBUTTON, &wm);
    while (window.isOpen()) {
        inputManager.collectInputEvents(window);
        inputManager.processEvents(window);
        if (timer.getElapsedTime() > sf::milliseconds(10.f)) {
            timer.restart();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            wm.updateWidgets();
            window.clear();
            wm.drawWidgets(window);
            window.display();
        }

    }

    return 0;
} // Main function