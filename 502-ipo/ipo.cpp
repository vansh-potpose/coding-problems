#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i)
            projects.push_back({Capital[i], Profits[i]});

        // Sort by required capital
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k--) {
            // Add all affordable projects to max heap
            while (i < n && projects[i].first <= W)
                maxHeap.push(projects[i++].second);

            // No project can be done
            if (maxHeap.empty()) break;

            // Select the best profit
            W += maxHeap.top();
            maxHeap.pop();
        }

        return W;
    }
};
