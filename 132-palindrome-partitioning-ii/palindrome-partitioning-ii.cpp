class Solution {
public:
    bool isPal(string& s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }

    int f(int idx,string  &s, vector<int>& dp) {
        if (idx == s.size()) return -1; // No cut needed after the last partition
        if (dp[idx] != -1) return dp[idx];

        int minCuts = INT_MAX;
        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                minCuts = min(minCuts, 1 + f(i + 1, s, dp));
            }
        }
        return dp[idx] = minCuts;
    }

    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return f(0, s, dp);
    }
};