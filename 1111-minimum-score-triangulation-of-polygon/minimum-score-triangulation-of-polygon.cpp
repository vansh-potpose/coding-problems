class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int len=2;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=INT_MAX;

                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[j]*values[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};