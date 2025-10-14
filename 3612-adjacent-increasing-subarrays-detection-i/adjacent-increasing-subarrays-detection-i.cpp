class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        bool result=false;
        for(int i=1;i<nums.size();i++){
            int count1=1;
            while(i<nums.size() && nums[i]>nums[i-1]){
                count1++;
                i++;
            }
            
            if(count1>=k){
                result=true;
            }else{
                continue;
            }
            if(count1>= 2*k){
                return true;
            }
            i++;
            int count2=1;
            while(i<nums.size() && nums[i]>nums[i-1]){
                count2++;
                i++;
                
            }
            if(count2>=k){
                if(result){
                    return true;
                }
            }
        }
        return false;
    }
};