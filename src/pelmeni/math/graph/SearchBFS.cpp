#include <limits>
#include <algorithm>
#include <cstdio>

#include "math/graph/SearchBFS.hpp"

namespace p2d { namespace math {
    SearchBFS::SearchBFS(const Graph& graph, const size_t n_start) 
    : SearchBFS(graph, n_start, n_start) {;}

    SearchBFS::SearchBFS(const Graph& graph, const size_t n_start, const size_t n_end) 
    : node_start(n_start),
      node_end(n_end),
      adjacencyList(graph.getAdjacencyList()) {
      }

    std::vector<size_t> SearchBFS::fill() {
        std::vector<bool> visited(adjacencyList.size(), false);
        std::vector<size_t> nodeList;
        std::queue<size_t> frontier;

        frontier.push(node_start); 
        while (!frontier.empty()) {
            const size_t current_node = frontier.front();
            const EdgeList& edges = adjacencyList[current_node].getEdges();
            for (auto& edge : edges) {
                if (!visited[edge.nodeId]) {
                    frontier.push(edge.nodeId);
                }
            }
            visited[current_node] = true;
            nodeList.push_back(current_node);
            frontier.pop();
        }

        return nodeList;
    }

    Path SearchBFS::getShortestPath() {
        const float maxCost = std::numeric_limits<float>::max();
        std::vector<PathStep> pathCosts(adjacencyList.size(), PathStep{0, maxCost});
        std::vector<bool> visited(adjacencyList.size(), false);
        std::queue<size_t> frontier;

        pathCosts[node_start] = PathStep{node_start, 0.f};

        // Traverse graph and calculate cost
        frontier.push(node_start);
        while (!frontier.empty()) {
            const size_t currentNode = frontier.front();
            const EdgeList& edges = adjacencyList[currentNode].getEdges();
            for (auto& edge : edges) {
                const size_t targetNode = edge.nodeId;
                const float costHere = pathCosts[currentNode].cost;
                const float costThere = pathCosts[targetNode].cost;
                const float costAcrossEdge = edge.weight;
                const float costToTarget = costHere + costAcrossEdge;
                if (costToTarget < costThere) {
                    pathCosts[targetNode] = PathStep{currentNode, costToTarget};
                    frontier.push(targetNode);
                }
            }
            visited[currentNode] = true;
            frontier.pop();
        }

        // Construct the shortest path reversed
        const float totalCost = pathCosts[node_end].cost;
        std::vector<size_t> reversedPath;
        size_t currentNode = node_end;
        while (currentNode != node_start) {
            reversedPath.push_back(currentNode);
            const size_t previousNode = pathCosts[currentNode].previousNode;
            currentNode = previousNode;
        }

        // Finish off with the start node and reverse
        reversedPath.push_back(node_start);
        std::reverse(reversedPath.begin(), reversedPath.end());

        // Return the path
        return Path{totalCost, std::move(reversedPath)};
    }
}
}
