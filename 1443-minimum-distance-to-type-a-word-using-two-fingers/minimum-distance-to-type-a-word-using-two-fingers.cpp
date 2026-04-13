class Solution {
public:
    int cal(int a, int b) {
        int ax = a / 6, ay = a % 6, bx = b / 6, by = b % 6;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string s) {
        int n = s.size(), dp[300][26][26];

        for (int i = 0; i < n; i++) {
            int t = s[i] - 'A';
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][k] = 1e6;
                }
            }
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][t] = min(dp[i + 1][j][t], dp[i][j][k] + cal(k, t));
                    dp[i + 1][t][k] = min(dp[i + 1][t][k], dp[i][j][k] + cal(j, t));
                }
            }
        }

        int ans = 1e6;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ans = min(ans, dp[n][j][k]);
            }
        }
        return ans;
    }
};