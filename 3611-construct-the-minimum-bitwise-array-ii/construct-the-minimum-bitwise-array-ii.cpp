class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& n : nums) {
            n = n ^ (((n + 1) & ~n) >> 1) | ((n & 1) - 1);
        }
        return move(nums);
    }
};