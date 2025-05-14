class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n1 = text.size();
        int n2 = pattern.size();
        vector<bool> prev(n2 + 1, false), curr(n2 + 1, false);
        prev[0] = true;

        for (int j = 1; j <= n2; j++) {
            if (pattern[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        if (n2 == 0 && n1 > 0) {
            return false;
        }

        for (int i = 1; i <= n1; i++) {
            bool flag = true;
            for (int j = 1; j <= n2; j++) {
                if (pattern[j - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= n2; j++) {
                if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (pattern[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
};