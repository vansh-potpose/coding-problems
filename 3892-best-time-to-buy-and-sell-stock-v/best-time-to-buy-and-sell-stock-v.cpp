struct State {
    long long maxProfit, buyHold, sellHold;
    State(long long p = 0, long long b = 0, long long s = 0) : maxProfit(p), buyHold(b), sellHold(s) {}
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int firstPrice = prices[0];
        vector<State> dp(k + 1, State(0, -firstPrice, firstPrice));
        const int n = prices.size();
        
        for (int day = 1; day < n; day++) {
            const int currPrice = prices[day];
            for (int trans = k; trans > 0; trans--) {
                auto& [profit, buy, sell] = dp[trans];
                const long long prevProfit = dp[trans - 1].maxProfit;
                profit = max(profit, max(buy + currPrice, sell - currPrice));
                buy = max(buy, prevProfit - currPrice);
                sell = max(sell, prevProfit + currPrice);
            }
        }
        
        return dp[k].maxProfit;
    }
};