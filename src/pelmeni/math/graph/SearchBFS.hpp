#pragma once

#include <cstdlib>
#include <vector>
#include <queue>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    struct PathStep {
        const size_t node;
        const float cost;
    }; // struct PathStep

    struct Path {
        const size_t node_start;
        const size_t node_end;

        std::vector<PathStep> pathSteps;
    }; // struct Path

    class SearchBFS {
    public:
        SearchBFS(const Graph& graph, const size_t n_start);
        SearchBFS(const Graph& graph, const size_t n_start, const size_t n_end);
        std::vector<size_t> fill();
    private:
        std::vector<bool> visited;
        std::queue<size_t> frontier;

        const size_t node_start;
        const size_t node_end;
        const std::vector<Node>& adjacencyList;
    }; // class SearchBFS
}
}