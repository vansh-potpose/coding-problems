class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int i=0;
        pair<int,int> maxOr={0,0};
        while(i<nums.size()){
            if(nums[i]>maxOr.first){
                maxOr.first=nums[i];
                maxOr.second=0;
                while(i<nums.size() && nums[i]==maxOr.first){
                    i++;
                    maxOr.second+=1;
                }
            }else if(maxOr.first==nums[i]){
                int temp=0;
                while(nums[i]==maxOr.first){
                    i++;
                    temp++;
                }
                maxOr.second=max(temp,maxOr.second);
            }else{
                i++;
            }
        }
        return maxOr.second;
    }
};