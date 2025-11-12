class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n=nums.size();
        int res=INT_MAX,cnt=0;

        for(int i=0;i<n;i++){
            cnt+=(nums[i]==1);
        }
        if(cnt)return n-cnt;

        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    res=min(res,j-i+n-1);
                    break;
                }
            }
        }
        return res==INT_MAX ? -1:res;
    }
};