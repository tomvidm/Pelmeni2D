#include <algorithm>
#include <cstdio>

#include "math/graph/Dijkstra.hpp"

namespace p2d { namespace math {
    Path shortestPath_Dijkstra(const Graph& graph, const size_t nodeStart, const size_t nodeEnd) {
        CostCounter costCounter = precalculatedGraphCosts(graph, nodeStart);
        Path shortestPath;

        size_t currentNode = nodeEnd;
        while (currentNode != nodeStart) {
            shortestPath.push_back(costCounter[currentNode]);
            currentNode = costCounter[currentNode].previousNode;
        }

        shortestPath.push_back(costCounter[nodeStart]);
        std::reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }

    CostCounter precalculatedGraphCosts(const Graph& graph, const size_t sourceNode) {
        CandidateQueue candidateQueue;
        candidateQueue.push(Candidate{sourceNode, 0.f});

        CostCounter costCounter = prepareInititalCostCounter(graph.getAdjacencyList().size(), sourceNode);

        while (!candidateQueue.empty()) {
            const Candidate currentCandidate = candidateQueue.front();
            const Node& currentNode = graph[currentCandidate.nodeId];
            const EdgeList& edges = currentNode.getEdges();
            candidateQueue.pop();
            
            for (auto& edge : edges) {
                const size_t targetNode = edge.nodeId;
                const float costHere = costCounter[currentCandidate.nodeId].costToThis;
                const float costThere = costCounter[targetNode].costToThis;
                const float costAcrossEdge = edge.weight;
                const float costToTarget = costHere + costAcrossEdge;
                if (costToTarget < costThere) {
                    costCounter[targetNode] = Step{targetNode, currentCandidate.nodeId, costToTarget};
                    candidateQueue.push(Candidate{targetNode, costToTarget});
                }
            }
        }
        return costCounter;
    } // findShortestPath
    
    CostCounter prepareInititalCostCounter(const size_t numNodes, const size_t sourceNode) {
        const float infinity = std::numeric_limits<float>::max();
        std::vector<Step> initialCostCounter(numNodes, Step{0, 0, infinity});
        initialCostCounter[sourceNode] = Step{sourceNode, sourceNode, 0.f};
        return std::move(initialCostCounter);
    }

    bool operator == (const Step& lhs, const Step& rhs) {
        return lhs.thisNode == rhs.thisNode &&
               lhs.previousNode == rhs.previousNode &&
               lhs.costToThis == rhs.costToThis;
    }
}
}