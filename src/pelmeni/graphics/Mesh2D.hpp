#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "system/Transformable2.hpp"
#include "math/Vector.hpp"

#include "graphics/MeshData2D.hpp"

namespace p2d { namespace graphics {
    using sf::VertexArray;

    class Mesh2D : public system::Transformable2, public sf::Drawable {
    public:
        Mesh2D();
        void update();
        void updateMesh();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        MeshData2D meshData;
        VertexArray verticesToDraw;
    }; // class Mesh2D
} // namespace graphics
} // namespace p2d