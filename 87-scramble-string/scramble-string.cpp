class Solution {
public:
unordered_map<string, bool> memo;

    bool isScrambleUtil(const string& s1, const string& s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        string key = s1 + " " + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.length();

        // Prune early: if characters don't match in frequency, return false
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return memo[key] = false;

        for (int i = 1; i < n; ++i) {
            // Without swap
            if (isScrambleUtil(s1.substr(0, i), s2.substr(0, i)) &&
                isScrambleUtil(s1.substr(i), s2.substr(i)))
                return memo[key] = true;

            // With swap
            if (isScrambleUtil(s1.substr(0, i), s2.substr(n - i)) &&
                isScrambleUtil(s1.substr(i), s2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
    bool isScramble(string s1, string s2) {
         return isScrambleUtil(s1, s2);
    }
};