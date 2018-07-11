#pragma once

#include <memory>
#include <vector>
#include <array>

#include "SFML/Graphics.hpp"

#include "system/Transformable2.hpp"
#include "math/Vector.hpp"

#include "graphics/MeshData2D.hpp"

namespace p2d { namespace graphics {
    using sf::VertexArray;
    using QuadTextureCoordinates = std::array<math::Vector2f, 4>;
    class Mesh2D : public sf::Drawable {
    public:
        using shared = std::shared_ptr<Mesh2D>;
    public:
        Mesh2D();
        void buildMesh();
        
        void setRenderEdges(const bool& yesno);
        void setMeshData(std::shared_ptr<MeshData2D> extMeshData);
        void setEdgeColor(const size_t& e, const sf::Color& color);
        void setQuadColor(const size_t& q, const sf::Color& color);
        void setQuadTextureCoordinates(const size_t& q, const QuadTextureCoordinates& texCoord);

        sf::Vertex* getEdgeVertices(const size_t& e);
        sf::Vertex* getQuadVertices(const size_t& q);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        bool renderEdges = true;
        bool renderQuads = true;

        std::shared_ptr<MeshData2D> meshData = nullptr;
        VertexArray linesToDraw;
        VertexArray quadsToDraw;
    }; // class Mesh2D
} // namespace graphics
} // namespace p2d