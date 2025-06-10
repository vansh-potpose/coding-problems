class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Optimization: if k is large, use greedy solution
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int d = 1; d < n; ++d) {
                dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
            }
        }

        return dp[k][n - 1];
    }
};
