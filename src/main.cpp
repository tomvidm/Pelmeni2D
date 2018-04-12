#include <iostream>
#include <cstdio>
#include <tuple>

#include "SFML/Graphics.hpp"

#include "math/Vector.hpp"
#include "physics/Body2D.hpp"
#include "physics/Spring2D.hpp"

p2d::math::Vector2f getMousePosition(sf::RenderWindow& window) {
    const sf::Vector2i mpos = sf::Mouse::getPosition(window);
    return ::p2d::math::Vector2f(
        static_cast<float>(mpos.x),
        static_cast<float>(mpos.y)
        );
}

int main() {
    using namespace p2d;

    std::vector<physics::Body2D> bodies = {
        physics::Body2D(math::Vector2f(300.f, 100.f), 1.f),
        physics::Body2D(math::Vector2f(250.f, 150.f), 1.f),
        physics::Body2D(math::Vector2f(350.f, 150.f), 1.f),
        physics::Body2D(math::Vector2f(250.f, 200.f), 1.f),
        physics::Body2D(math::Vector2f(350.f, 200.f), 1.f),
        physics::Body2D(math::Vector2f(250.f, 250.f), 1.f),
        physics::Body2D(math::Vector2f(350.f, 250.f), 1.f),
        physics::Body2D(math::Vector2f(250.f, 300.f), 1.f),
        physics::Body2D(math::Vector2f(350.f, 300.f), 1.f),
        physics::Body2D(math::Vector2f(300.f, 350.f), 1.f)
    };

    std::vector<std::tuple<size_t, size_t>> edges = {
        std::make_tuple(0,1),
        std::make_tuple(0,2),
        std::make_tuple(1,2),
        std::make_tuple(1,3),
        std::make_tuple(2,4),
        std::make_tuple(3,4),
        std::make_tuple(3,5),
        std::make_tuple(4,6),
        std::make_tuple(5,6),
        std::make_tuple(5,7),
        std::make_tuple(6,8),
        std::make_tuple(7,8),
        std::make_tuple(7,9),
        std::make_tuple(8,9)
    };

    bodies[0].setFixed(true);
    bodies[9].setFixed(true);

    sf::VertexArray vertices;
    vertices.setPrimitiveType(sf::PrimitiveType::Lines);
    vertices.resize(2 * edges.size());

    physics::Spring2D spring(15.f, 2.5f, 50.f);

    sf::RenderWindow window(sf::VideoMode(640, 480), "Testapp_WireMesh");
    sf::Clock timer;
    sf::Event event;
    while (window.isOpen()) {
        const float dt = timer.restart().asSeconds();
        const math::Vector2f mpos = getMousePosition(window);

        bodies[9].setPosition(mpos);

        for (auto& edge : edges) {
            physics::Body2D& b0 = bodies[std::get<0>(edge)];
            physics::Body2D& b1 = bodies[std::get<1>(edge)];
            const physics::Force2 force = spring.calculateForce(b0, b1);
            b0.applyForce(-force, dt);
            b1.applyForce(force, dt);
        }

        for (auto& body : bodies) {
            body.applyTime(dt);
        }

        for (size_t i = 0; i < edges.size(); i++) {
            const size_t a = std::get<0>(edges[i]);
            const size_t b = std::get<1>(edges[i]);
            const math::Vector2f v0 = bodies[a].getPosition();
            const math::Vector2f v1 = bodies[b].getPosition();
            vertices[2*i].position = v0;
            vertices[2*i + 1].position = v1;
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(vertices);
        window.display();
    }

    return 0;
} // Main function