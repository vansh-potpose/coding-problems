class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=INT_MAX,minidx=0,maxidx=0;
        while(j<nums.size()){
            if(nums[minidx]>nums[j]) minidx=j;
            if(nums[maxidx]<nums[j]) maxidx=j;
            if(j-i+1>k){
                if(i==minidx) minidx++;
                else if(i==maxidx) maxidx++;
                i++;
            }if(j-i+1==k) ans=min(ans,nums[maxidx]-nums[minidx]);
            j++;
        }return ans;
    }
};