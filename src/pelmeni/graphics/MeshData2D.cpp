#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
    MeshData2D::MeshData2D() {
        ;
    } // constructor

    MeshData2D::MeshData2D(const MeshVertices& mVecs, const MeshEdges& mEdges, const MeshQuads& mQuads) 
    : meshVertices(mVecs), meshEdges(mEdges), meshQuads(mQuads) {
        ;
    } // constructor

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
} // namespace graphics
} // namespace p2d