#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
        Mesh2D::Mesh2D() {
            verticesToDraw.setPrimitiveType(sf::PrimitiveType::Lines);
        }
    
        void Mesh2D::transformMesh(const math::Transform& transform) {
            size_t i = 0;
            for (auto& edge : meshData->getMeshEdges()) {
                MeshVertices& vertices = meshData->getMeshVertices();
                const Mesh2DVertex v0 = transform.transformVector(vertices[edge.v0]);
                const Mesh2DVertex v1 = transform.transformVector(vertices[edge.v1]);
                verticesToDraw[i++].position = v0;
                verticesToDraw[i++].position = v1;
            }
        } // tranformMesh

        void Mesh2D::setMeshData(std::shared_ptr<MeshData2D> extMeshData) {
            meshData = extMeshData;
            verticesToDraw.resize(2 * meshData->getNumEdges());
        }

        void Mesh2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(verticesToDraw);
        }
} // namespace graphics
} // namespace p2d