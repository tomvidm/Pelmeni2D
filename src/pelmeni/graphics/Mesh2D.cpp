#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
        void Mesh2D::update() {
            if (needsUpdate()) {
                updateMesh();
            }
        }
    
        void Mesh2D::updateMesh() {
            size_t i = 0;
            for (auto& edge : meshData.getMeshEdges()) {
                MeshVertices& vertices = meshData.getMeshVertices();
                const Mesh2DVertex v0 = getTransform().transformVector(vertices[edge.v0]);
                const Mesh2DVertex v1 = getTransform().transformVector(vertices[edge.v1]);
                verticesToDraw[i++].position = v0;
                verticesToDraw[i++].position = v1;
            }
        } // tranformMesh

        void Mesh2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(verticesToDraw);
        }
} // namespace graphics
} // namespace p2d