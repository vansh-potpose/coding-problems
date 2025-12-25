class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long sum=0;
        for(int i=0;i<k;i++){
            int temp=happiness[i]-i;
            sum+=temp>0?temp:0;
        }
        return sum;
    }
};