class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            return abs(nums[0]-nums[1]);
        }

        sort(nums.begin(),nums.end());
        int max_v=0;
        for(int i=1;i<nums.size();i++){
            max_v=max(nums[i]-nums[i-1],max_v);  
        }
        return max_v;
    }
};