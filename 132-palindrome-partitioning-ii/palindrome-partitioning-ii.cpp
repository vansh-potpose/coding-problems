class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i] = i; // max cuts at worst: cut each character
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;
                    // If s[0..i] is a palindrome, no cut needed
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};