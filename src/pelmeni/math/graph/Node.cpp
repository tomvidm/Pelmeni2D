#include "math/graph/Node.hpp"
namespace p2d { namespace math {
    void Node::addEdge(const Edge& edge) {
        edges.push_back(edge);
    }

    bool Node::hasEdgeTo(const size_t node) const {
        for (auto& edge : edges) {
            if (edge.nodeId == node) {
                return true;
            }
        } 
        return false;
    }

    const EdgeList& Node::getEdges() const {
        return edges;
    }
}
}