class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+nums1[i-1]*nums2[j-1]);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        if(nums1[0]>0 && nums2[m-1]<0){
            int maxi = nums1[0]*nums2[m-1];
            return maxi;
        }
        if(nums1[n-1]<0 && nums2[0]>0){
            int maxi = nums1[n-1]*nums2[0];
            return maxi;
        }
        return dp[n][m];
    }
};