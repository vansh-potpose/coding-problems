class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> itinerary;

    void dfs(const string& airport) {
        while (!graph[airport].empty()) {
            auto next = *graph[airport].begin(); // smallest lexical destination
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }
        itinerary.push_back(airport); // post-order
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
