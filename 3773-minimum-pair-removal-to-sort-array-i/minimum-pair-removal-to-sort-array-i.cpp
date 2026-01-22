class Solution {
public:
    bool isNotSorted(const vector<int>& nums) {
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] > nums[i + 1]) return true;
        }
        return false;
    }
    
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (isNotSorted(nums)) {
            int idx = 0;
            int minSum = nums[0] + nums[1];
            for (int i = 1; i + 1 < (int)nums.size(); i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + (idx + 1));
            
            operations++;
        }
        
        return operations;
    }
};