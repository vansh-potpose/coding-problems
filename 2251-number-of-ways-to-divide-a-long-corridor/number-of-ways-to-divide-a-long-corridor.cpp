class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> pos;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }
        
        if (pos.size() % 2 or pos.size() == 0) {
            return 0;
        }
        
        long res = 1;
        for (int i = 2; i < pos.size(); i += 2) {
            int len_of_gap = pos[i] - pos[i - 1];
            res = (res * len_of_gap) % mod;
        }

        return res;
    }
};