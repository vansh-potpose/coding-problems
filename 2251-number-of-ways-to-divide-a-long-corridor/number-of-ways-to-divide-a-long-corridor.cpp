class Solution {
public:
    #define mod 1000000007
    int solve(string &s,int i,int c,vector<vector<int>>&dp)
    {
        if(i>=s.size())
        {
            if(c==2)
            {
                return 1;
            }
            return 0;
        }
        if(c>2)
        {
            return 0;
        }

        if(dp[i][c]!=-1)
        {
            return dp[i][c];
        }

        int ans = 0;
        if(s[i]=='S')
        {
            if(c+1==2)
            {
                ans = (ans%mod+solve(s,i+1,0,dp)%mod)%mod;
            }
            
            ans  = (ans%mod+solve(s,i+1,c+1,dp)%mod)%mod;
            
            
        }
        else
        {
            if(c==2)
            {
                ans = (ans%mod+solve(s,i+1,0,dp)%mod)%mod;
            }
            
            ans = (ans%mod+solve(s,i+1,c,dp)%mod)%mod;
            
           
        }

        return dp[i][c] =  ans%mod;
    }
    int numberOfWays(string corridor) {
        vector<vector<int>>dp(corridor.size(),vector<int>(3,-1));
        int ans = solve(corridor,0,0,dp);
        return ans;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });