#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/WireMesh.hpp"

#define ROWS 12
#define COLUMNS 16

namespace testapps {
    class ProjectionTesting {
    public:
        ProjectionTesting();
        void loop();

    private:
        sf::RenderWindow window;
        std::array<p2d::graphics::WireMesh, ROWS * COLUMNS> meshes;
        
        static const p2d::graphics::Vector3List vector3List;
        static const p2d::graphics::EdgeList edgeList;
    }; // projectionTesting
}