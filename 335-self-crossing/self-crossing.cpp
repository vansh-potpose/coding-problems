class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n = d.size();
        for (int i = 3; i < n; ++i) {
            // Case 1: current line crosses the line 3 steps ahead of it
            if (d[i] >= d[i - 2] && d[i - 1] <= d[i - 3])
                return true;

            // Case 2: current line overlaps the line 4 steps ahead of it
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2])
                return true;

            // Case 3: current line crosses the line 5 steps ahead of it
            if (i >= 5 &&
                d[i - 2] >= d[i - 4] &&
                d[i] + d[i - 4] >= d[i - 2] &&
                d[i - 1] <= d[i - 3] &&
                d[i - 1] + d[i - 5] >= d[i - 3])
                return true;
        }
        return false;
    }
};
