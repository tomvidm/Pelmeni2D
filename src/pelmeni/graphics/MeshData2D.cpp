#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
    MeshData2D::MeshData2D() {
        ;
    } // constructor

    MeshData2D::MeshData2D(const MeshVertices& mVecs, const MeshEdges& mEdges, const MeshQuads& mQuads) 
    : meshVertices(mVecs), meshEdges(mEdges), meshQuads(mQuads) {
        ;
    } // constructor

    MeshData2D::MeshData2D(const math::ConvexPolygon& convexPolygon) {
        setMeshVertices(convexPolygon.getVertices());
        for (size_t i = 0; i < meshVertices.size(); i++) {
            const EdgeIndices edgeIndices = {i, (i + 1) % meshVertices.size()};
            meshEdges.push_back(edgeIndices);
        }
    }

    void MeshData2D::setMeshVertices(const MeshVertices& mVecs) {
        meshVertices = mVecs;
    } // setMeshVectors

    void MeshData2D::setMeshEdges(const MeshEdges& mEdges) {
        meshEdges = mEdges;
    } // setMeshEdges

    void MeshData2D::setMeshQuads(const MeshQuads& mQuads) {
        meshQuads = mQuads;
    } // setMeshQuads

    MeshVertices& MeshData2D::getMeshVertices() {
        return meshVertices;
    } // setMeshVectors
    
    MeshEdges& MeshData2D::getMeshEdges() {
        return meshEdges;
    } // getMeshEdges

    MeshQuads& MeshData2D::getMeshQuads() {
        return meshQuads;
    }

    EdgeVertices MeshData2D::getVerticesForEdge(const size_t e) const {
        EdgeIndices edgeIndices = meshEdges[e];
        return EdgeVertices{
            meshVertices[edgeIndices.v[0]],
            meshVertices[edgeIndices.v[1]]
        };
    }
} // namespace graphics
} // namespace p2d