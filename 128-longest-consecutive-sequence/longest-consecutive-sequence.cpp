class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        int count = 1;
        vector<int> res;
        if (nums.size() == 0) {
            return 0;
        }
        for (i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] == nums[i]) {
                continue; 
            }
            if (nums[i + 1] - nums[i] == 1) {
                count++;
            }

            else {
                res.push_back(count);
                count = 1;
            }
        }
        res.push_back(count);
        sort(res.begin(), res.end());
        return res[res.size() - 1];
    }
};