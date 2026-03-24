class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int bit = 30; bit >= 0; --bit) {
            int candidate = ans | (1 << bit);
            unordered_set<int> seen;
            seen.reserve(min(nums.size(), size_t{1} << (31 - bit)));
            for (int x : nums) {
                x = x & candidate;
                if (seen.insert(x).second) {
                    if (seen.contains(candidate ^ x)) {
                        ans = candidate;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};