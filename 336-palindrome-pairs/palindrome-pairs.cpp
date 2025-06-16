class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> res;

        // Map each word to its index
        for (int i = 0; i < words.size(); ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            int len = word.size();

            for (int j = 0; j <= len; ++j) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                // Case 1: left part is palindrome, check for reversed right in map
                if (isPalindrome(word, 0, j - 1)) {
                    if (mp.count(right) && mp[right] != i)
                        res.push_back({mp[right], i});
                }

                // Case 2: right part is palindrome, check for reversed left in map
                // j < len ensures no duplicates when j == len (empty right already handled)
                if (j < len && isPalindrome(word, j, len - 1)) {
                    if (mp.count(left) && mp[left] != i)
                        res.push_back({i, mp[left]});
                }
            }
        }

        return res;
    }
};
