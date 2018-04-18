#include <limits>
#include <queue>
#include <deque>

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    struct Candidate {
        struct Compare {
            bool operator() (const Candidate& lhs, const Candidate& rhs) {
                return lhs.cost < rhs.cost;
            }
        }; // struct Candidate::Compare
        size_t nodeId;
        float cost;
    }; // struct Candidate

    using CandidateQueue = std::priority_queue<Candidate, std::deque<Candidate>, Candidate::Compare>;

    struct Step {
        size_t thisNode;
        size_t previousNode;
        float costToThis;
    }; // struct Step

    using Path = std::vector<Step>;
    using CostCounter = std::vector<Step>;

    Path shortestPath_Dijkstra(const Graph& graph, const size_t nodeStart, const size_t nodeEnd);
    CostCounter precalculatedGraphCosts(const Graph& graph, const size_t sourceNode);
    CostCounter prepareInititalCostCounter(const size_t numNodes, const size_t sourceNode);

    bool operator == (const Step& lhs, const Step& rhs);
}
}