class Solution {
public:
    int check(int i,vector<int> &nums,int maxOR, int curr){
    
        if(i==nums.size()){
            return curr==maxOR?1:0;
        }

        if(curr==maxOR){
            return 1<<(nums.size()-i);
        }
        return check(i+1,nums,maxOR,curr|nums[i]) + check(i+1,nums,maxOR,curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0;
        for(auto i : nums){
            maxOR|=i;
        }

        return check(0,nums,maxOR,0);

    }   
};