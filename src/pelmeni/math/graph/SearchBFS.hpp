#pragma once

#include <cstdlib>
#include <vector>
#include <queue>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    struct PathStep {
        size_t previousNode;
        float cost;
    }; // struct PathStep

    struct Path {
        const float totalCost;
        std::vector<size_t> nodes;
    }; // struct Path

    class SearchBFS {
    public:
        SearchBFS(const Graph& graph, const size_t n_start);
        SearchBFS(const Graph& graph, const size_t n_start, const size_t n_end);
        
        Path getShortestPath();

        std::vector<size_t> fill();
    private:
        const size_t node_start;
        const size_t node_end;
        const std::vector<Node>& adjacencyList;
    }; // class SearchBFS
}
}