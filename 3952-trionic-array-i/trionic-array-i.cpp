class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), peak = -1,valley = n;

        for (int i = 0; i < n - 1; i++) {
            if (peak == -1 && nums[i] >= nums[i + 1])
                peak = i;

            if (valley == n && nums[n - 1 - i] <= nums[n - 2 - i])
                valley = n - 1 - i;

            if (peak > 0 && valley < n - 1)
                return peak < valley && isDecreasing(nums, peak, valley);
        }

        return false;
    }

    bool isDecreasing(vector<int>& nums, int a, int b) {
        for (int i = a; i < b; i++)
            if (nums[i] <= nums[i + 1])
                return false;
        return true;
    }
};
