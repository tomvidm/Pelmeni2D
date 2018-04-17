#include "math/graph/SearchBFS.hpp"

namespace p2d { namespace math {
    SearchBFS::SearchBFS(const Graph& graph, const size_t n_start) 
    : SearchBFS(graph, n_start, n_start) {;}

    SearchBFS::SearchBFS(const Graph& graph, const size_t n_start, const size_t n_end) 
    : node_start(n_start),
      node_end(n_end),
      adjacencyList(graph.getAdjacencyList()) {
          visited.resize(adjacencyList.size());
          for (size_t i = 0; i < visited.size(); i++) {
              visited[i] = false;
          }
      }

    std::vector<size_t> SearchBFS::fill() {
        std::vector<size_t> nodeList;
        frontier.push(node_start); 
        while (!frontier.empty()) {
            const size_t node = frontier.front();
            const EdgeList& edges = adjacencyList[node].getEdges();
            for (auto& edge : edges) {
                if (!visited[edge.nodeId]) {
                    frontier.push(edge.nodeId);
                }
            }
            visited[node] = true;
            nodeList.push_back(node);
            frontier.pop();
        }

        return nodeList;
    }
}
}
