class Solution {
public:
    vector<string> maxNumOfSubstrings(string S) {
        const int N = S.size();
        vector<int> mins(26, INT_MAX), maxs(26, -1);
        vector<bool> exists(26, false);
        vector<vector<int>> prefixSum(N + 1, vector<int>(26, 0));

        // Precompute mins, maxs, existence, and prefix sums
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 26; ++j) {
                prefixSum[i + 1][j] = prefixSum[i][j];
            }
            int ch = S[i] - 'a';
            prefixSum[i + 1][ch]++;
            mins[ch] = min(mins[ch], i);
            maxs[ch] = max(maxs[ch], i);
            exists[ch] = true;
        }

        // Build graph
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; ++i) {
            if (exists[i]) {
                for (int j = 0; j < 26; ++j) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0) {
                        graph[i][j] = true;
                    }
                }
            }
        }

        // Kosaraju's algorithm (1st pass)
        vector<bool> visited(26, false);
        vector<int> stack;
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && !visited[i]) {
                dfs1(i, graph, visited, stack);
            }
        }

        // Kosaraju's algorithm (2nd pass)
        int batch = 0;
        vector<int> batches(26, -1);
        vector<int> degree(26, 0);

        while (!stack.empty()) {
            int v = stack.back(); stack.pop_back();
            if (batches[v] < 0) {
                dfs2(v, graph, batches, batch, degree);
                batch++;
            }
        }

        // Collect results: only substrings whose SCC has out-degree = 0
        vector<string> result;
        for (int i = batch - 1; i >= 0; --i) {
            if (degree[i] == 0) {
                int minIdx = INT_MAX, maxIdx = -1;
                for (int j = 0; j < 26; ++j) {
                    if (batches[j] == i) {
                        minIdx = min(minIdx, mins[j]);
                        maxIdx = max(maxIdx, maxs[j]);
                    }
                }
                result.push_back(S.substr(minIdx, maxIdx - minIdx + 1));
            }
        }

        return result;
    }

private:
    // First DFS: original graph, fill finishing order
    void dfs1(int v, const vector<vector<bool>>& graph, vector<bool>& visited, vector<int>& stack) {
        if (visited[v]) return;
        visited[v] = true;
        for (int i = 0; i < 26; ++i) {
            if (graph[v][i] && !visited[i]) {
                dfs1(i, graph, visited, stack);
            }
        }
        stack.push_back(v);
    }

    // Second DFS: reverse graph, assign components
    void dfs2(int v, const vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] < 0) {
            batches[v] = batch;
            for (int i = 0; i < 26; ++i) {
                if (graph[i][v]) {
                    dfs2(i, graph, batches, batch, degree);
                }
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]]++;
            }
        }
    }
};
