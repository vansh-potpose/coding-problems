class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()/2;
        if(nums[n]==nums[n-1]){
            return nums[n];
        }
        if(nums[n]==nums[nums.size()-1]){
            return nums[n];
        }
        return nums[n-1];
    }
};