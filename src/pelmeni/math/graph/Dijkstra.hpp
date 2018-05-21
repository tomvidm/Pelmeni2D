#pragma once

#include <limits>
#include <queue>
#include <deque>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    struct Candidate {
        size_t nodeId;
        float cost;
    }; // struct Candidate

    using CandidateQueue = std::queue<Candidate>;

    struct Step {
        size_t thisNode;
        size_t previousNode;
        float costToThis;
    }; // struct Step

    using Path = std::vector<Step>;
    using CostCounter = std::vector<Step>;

    Path shortestPath_Dijkstra(const Graph& graph, const size_t nodeStart, const size_t nodeEnd);
    Path shortestPath_Dijkstra(const size_t nodeStart, const size_t nodeEnd, const CostCounter& precalculatedCosts);
    CostCounter precalculatedGraphCosts(const Graph& graph, const size_t sourceNode);
    CostCounter prepareInititalCostCounter(const size_t numNodes, const size_t sourceNode);

    bool operator == (const Step& lhs, const Step& rhs);
}
}