class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int l=0,r=0;
        int sum=0,max_sum=0;
        while(l<=r && r<nums.size()){
            if(mp[nums[r]]){
                mp[nums[l]]--;
                sum-=nums[l];
                l++;
            }else{
                mp[nums[r]]++;
                sum+=nums[r];
                max_sum=max(sum,max_sum);
                r++;
            }
        }
        return max_sum;
    }
};