#include <vector>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    size_t Graph::addNodes(const size_t numNodes) {
        adjacencyList.resize(adjacencyList.size() + numNodes);
        return adjacencyList.size() - 1;
    }

    size_t Graph::addNode() {
        adjacencyList.push_back(Node());
        return adjacencyList.size() - 1;
    }

    void Graph::connect(const size_t node_a, const size_t node_b, const float weight) {
        if (std::max(node_a, node_b) < adjacencyList.size()) {
            adjacencyList[node_a].addEdge(Edge{node_a, node_b, weight});    
            adjacencyList[node_b].addEdge(Edge{node_a, node_a, weight});
        }
    }

    void Graph::connectTo(const size_t node_a, const size_t node_b, const float weight) {
        if (std::max(node_a, node_b) < adjacencyList.size()) {
            adjacencyList[node_a].addEdge(Edge{node_a, node_b, weight});    
        }
    }

    bool Graph::isConnected(const size_t node_a, const size_t node_b) const {
        return isConnectedTo(node_a, node_b) && isConnectedTo(node_b, node_a);
    }

    bool Graph::isConnectedTo(const size_t node_a, const size_t node_b) const {
        if (std::max(node_a, node_b) < adjacencyList.size()) {
            if (adjacencyList[node_a].hasEdgeTo(node_b)) {
                return true;
            } else return false;
        } else return false;
    }

    const AdjacencyList& Graph::getAdjacencyList() const {
        return adjacencyList;
    }

    const Node& Graph::operator[] (const size_t node) const {
        return adjacencyList[node];
    }
}
}