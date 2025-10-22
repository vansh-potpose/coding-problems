#include <vector>

class Solution {
private:
    std::vector<int> color;
    
    // DFS function to color nodes and check for conflicts
    bool dfs(int node, const std::vector<std::vector<int>>& graph, int currentColor) {
        // Assign the color to the current node
        color[node] = currentColor;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == 0) {
                // Neighbor is uncolored, recursively call with opposite color
                if (!dfs(neighbor, graph, currentColor * -1)) {
                    return false;
                }
            } else if (color[neighbor] == currentColor) {
                // Conflict: neighbor has the same color
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        // 0: uncolored, 1: Color A, -1: Color B
        color.assign(n, 0);

        // Iterate through all nodes to cover disconnected components
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                // Start DFS from uncolored node, assign initial color -1
                if (!dfs(i, graph, -1)) {
                    return false;
                }
            }
        }
        return true;
    }
};