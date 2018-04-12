#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
    Mesh2D::Mesh2D() {
        vertices.setPrimitiveType(sf::PrimitiveType::Lines);
    } // constructor

    Mesh2D::Mesh2D(const MeshVectors& mVecs, const MeshEdges& mEdges) 
    : meshVectors(mVecs), meshEdges(mEdges) {
        vertices.resize(2*meshEdges.size());
        vertices.setPrimitiveType(sf::PrimitiveType::Lines);
    } // constructor

    void Mesh2D::transform(const math::Transform& transformation) {
        for (size_t i = 0; i < meshEdges.size(); i++) {
            const size_t index0 = std::get<0>(meshEdges[i]);
            const size_t index1 = std::get<1>(meshEdges[i]);
            const math::Vector2f vector0 = transformation.transformVector(meshVectors[index0]);
            const math::Vector2f vector1 = transformation.transformVector(meshVectors[index1]);
            vertices[2*i].position = vector0;
            vertices[2*i + 1].position = vector1;
        }
    }

    void Mesh2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices);
    }
} // namespace graphics
} // namespace p2d