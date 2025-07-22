class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0,maxsum = 0,sum = 0;
        vector<int> hash(10001,-1);

        while(r<n)
        {
            if(hash[nums[r]] != -1)
            {
                while(l<= hash[nums[r]])
                {
                    sum-=nums[l];
                    l++;
                }
            }
            sum+=nums[r];
            maxsum = max(maxsum,sum);
            hash[nums[r]] = r;
            r++;
        }

        return maxsum;
    }
};