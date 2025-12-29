// https://www.youtube.com/@0x3f
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<int> groups[7][7];
        for (auto& s : allowed) {
            // A~F -> 1~6
            groups[s[0] & 31][s[1] & 31].push_back(s[2] & 31);
        }

        int n = bottom.size();
        vector<int> pyramid(n);
        for (int i = 0; i < n; i++) {
            pyramid[n - 1] |= (bottom[i] & 31) << (i * 3); // 等价于 pyramid[n-1][i] = bottom[i]&31
        }

        vector<uint8_t> vis(1 << ((n - 1) * 3));

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0) {
                return true;
            }

            if (vis[pyramid[i]]) {
                return false;
            }

            if (j == i + 1) {
                vis[pyramid[i]] = true;
                return dfs(i - 1, 0);
            }

            for (int top : groups[pyramid[i + 1] >> (j * 3) & 7][pyramid[i + 1] >> ((j + 1) * 3) & 7]) {
                pyramid[i] &= ~(7 << (j * 3)); // 清除之前填的字母，等价于 pyramid[i][j] = 0
                pyramid[i] |= top << (j * 3); // 等价于 pyramid[i][j] = top
                if (dfs(i, j + 1)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(n - 2, 0);
    }
};