#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width asc, height desc if width equal
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Step 2: Extract heights
        vector<int> heights;
        for (auto& env : envelopes)
            heights.push_back(env[1]);

        // Step 3: Apply LIS on heights using binary search
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) lis.push_back(h);
            else *it = h;
        }

        return lis.size();
    }
};
