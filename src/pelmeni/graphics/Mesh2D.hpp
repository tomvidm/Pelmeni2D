#pragma once

#include <vector>
#include <tuple>

#include "SFML/Graphics.hpp"

#include "system/Transformable2.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace graphics {
    class Mesh2D : public sf::Drawable {
    public:
        using MeshVectors = std::vector<math::Vector2f>;
        using MeshEdges = std::vector<std::tuple<size_t, size_t>>;

        Mesh2D();
        Mesh2D(const MeshVectors& mVecs, const MeshEdges& mEdges);

        void transform(const math::Transform& transformation);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        MeshVectors meshVectors;
        MeshEdges meshEdges;
        sf::VertexArray vertices;
    }; // class Mesh2D
} // namespace graphics
} // namespace p2d