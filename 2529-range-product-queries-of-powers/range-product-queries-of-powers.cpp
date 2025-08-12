class Solution {
public:
    vector<int> productQueries(int n, const vector<vector<int>>& queries) {
        constexpr int MOD = 1000000007;
        vector prefix {0};
        while (n) {
            const int j = __builtin_ctz(n);
            prefix.push_back(prefix.back() + j);
            n -= 1 << j;
        }
        n = prefix.back();
        vector ans {1}; ans.reserve(n);
        for (int i = 1; i <= n; i++)
            ans.push_back((ans.back() << 1) % MOD);
        vector<int> ret; ret.reserve(queries.size());
        for (const auto& q : queries)
            ret.push_back(ans[prefix[q[1] + 1] - prefix[q[0]]]);
        return ret;
    }
};