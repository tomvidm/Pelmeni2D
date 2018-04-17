#include <vector>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    size_t Graph::addNode() {
        adjacencyList.push_back(Node());
        return adjacencyList.size() - 1;
    }

    std::vector<size_t> Graph::addNodes(const size_t numNodes) {
        std::vector<size_t> ids;
        for (size_t i = 0; i < numNodes; i++) {
            ids.push_back(addNode());
        }
        return ids;
    }

    void Graph::connect(const size_t node_a, const size_t node_b, const float weight) {
        if (std::max(node_a, node_b) < adjacencyList.size()) {
            adjacencyList[node_a].addEdge(Edge{node_b, weight});    
            adjacencyList[node_b].addEdge(Edge{node_a, weight});
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
}
}