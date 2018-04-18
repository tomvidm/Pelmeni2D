#pragma once

#include <vector>

#include "math/graph/Node.hpp"

namespace p2d { namespace math {
    using AdjacencyList = std::vector<Node>;

    class Graph {
    public:
        size_t addNodes(const size_t numNodes);
        size_t addNode();

        void connect(const size_t node_a, const size_t node_b, const float weight = 1.f);
        bool isConnected(const size_t node_a, const size_t node_b) const;
        bool isConnectedTo(const size_t node_a, const size_t node_b) const;

        const AdjacencyList& getAdjacencyList() const;

        const Node& operator[] (const size_t node) const;
    private:
        AdjacencyList adjacencyList;
    }; // class Graph
}
}