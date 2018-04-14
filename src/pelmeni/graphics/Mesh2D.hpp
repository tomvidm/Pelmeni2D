#pragma once

#include <memory>
#include <vector>

#include "SFML/Graphics.hpp"

#include "system/Transformable2.hpp"
#include "math/Vector.hpp"

#include "graphics/MeshData2D.hpp"

namespace p2d { namespace graphics {
    using sf::VertexArray;

    class Mesh2D : public sf::Drawable {
    public:
        Mesh2D();
        void transformMesh(const math::Transform& transform);
        
        void setMeshData(std::shared_ptr<MeshData2D> extMeshData);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        std::shared_ptr<MeshData2D> meshData = nullptr;
        VertexArray linesToDraw;
        VertexArray quadsToDraw;
    }; // class Mesh2D
} // namespace graphics
} // namespace p2d