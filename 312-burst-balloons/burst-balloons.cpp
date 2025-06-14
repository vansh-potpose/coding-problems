#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add virtual balloons with value 1
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; ++i)
            arr[i + 1] = nums[i];

        // dp[i][j] = max coins from bursting balloons in (i, j)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // len is the length of the current interval
        for (int len = 2; len <= n + 1; ++len) {
            for (int left = 0; left + len <= n + 1; ++left) {
                int right = left + len;
                for (int k = left + 1; k < right; ++k) {
                    dp[left][right] = max(dp[left][right],
                        arr[left] * arr[k] * arr[right] + dp[left][k] + dp[k][right]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
