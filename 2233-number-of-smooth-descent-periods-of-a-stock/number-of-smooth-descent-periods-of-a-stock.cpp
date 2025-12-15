class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int n=prices.size();
        long long sum=1, des=1;
        for(int i=1; i<n; i++){
            des=(-(prices[i]+1==prices[i-1]) & des)+1;
            sum+=des;
        }
        return sum;
    }
};