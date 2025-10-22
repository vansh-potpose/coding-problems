class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int chr = s[i] - 'a';
            if (first[chr] == -1)
                first[chr] = i;
            last[chr] = i;
        }

        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int L = first[c], R = last[c];
            bool valid = true;
            for (int i = L; i <= R && valid; i++) {
                int x = s[i] - 'a';
                if (first[x] < L) valid = false;
                R = max(R, last[x]);
            }
            if (valid) intervals.emplace_back(L, R);
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) { return a.second < b.second; });

        vector<string> ans;
        int end = -1;
        for (auto [L, R] : intervals) {
            if (L > end) {
                ans.emplace_back(s.substr(L, R - L + 1));
                end = R;
            }
        }

        return ans;
    }
};