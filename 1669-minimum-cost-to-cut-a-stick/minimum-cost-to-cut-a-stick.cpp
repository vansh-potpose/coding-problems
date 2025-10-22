class Solution {
public:
    // int f(int i, int j, vector<int>& cuts) {
    //     if(i > j) return 0;
    //     int mini = INT_MAX;

    //     for(int k=i; k<=j; k++){
    //         int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts) + f(k+1, j,
    //         cuts); mini = min(mini, cost);
    //     }

    //     return mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                int minCost = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    minCost = min(minCost, cost);
                }
                dp[i][j] = (minCost == INT_MAX) ? 0 : minCost;
            }
        }

        return dp[0][m - 1];
    }
};