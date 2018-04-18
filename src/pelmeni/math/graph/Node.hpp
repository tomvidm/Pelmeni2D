#pragma once

#include <vector>
#include <cstdlib>

namespace p2d { namespace math {
    struct Edge {
        size_t nodeBegin;
        size_t nodeEnd;
        float weight;
    }; // struct Edge

    using EdgeList = std::vector<Edge>;

    class Node {
    public:
        void addEdge(const Edge& edge);
        bool hasEdgeTo(const size_t node) const;

        const EdgeList& getEdges() const;
    private:
        EdgeList edges;
    }; // struct Node
}
}