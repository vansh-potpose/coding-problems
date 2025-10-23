class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find the first decreasing element from the end
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If not found, reverse the array
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element just larger than nums[index] and swap
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the subarray after index
        reverse(nums.begin() + index + 1, nums.end());
    }
};