class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size(), res = 0;
        vector<int> count(256, 0);
        for (int i = 0, j = 0; i < N; ++i) {
            count[s[i]]++;
            while (count[s[i]] > 1) {
                count[s[j++]]--;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};