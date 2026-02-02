class Solution {
public:
    struct SmartWindow{
        int K;
        multiset<int> low, high;
        long long sumLow = 0;

        SmartWindow(int k) : K(k) {}

        int windowSize() const{
            return (int)low.size() + (int)high.size();
        }
        void rebalance() {
            int need = min(K, windowSize());

            while((int)low.size() > need){
                auto it = prev(low.end());
                int x = *it;
                low.erase(it);
                sumLow -= x;
                high.insert(x);
            }
            while((int)low.size() < need && !high.empty()){
                auto it = high.begin();
                int x = *it;
                high.erase(it);
                low.insert(x);
                sumLow += x;
            }
        }
        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                sumLow += x;
            }
            else{
                high.insert(x);
            }
            rebalance();
        }
        void remove(int x){
            auto itLow = low.find(x);
            if(itLow != low.end()){
                low.erase(itLow);
                sumLow -= x;
            }
            else{
                auto itHigh = high.find(x);
                if(itHigh != high.end()){
                    high.erase(itHigh);
                }
            }
            rebalance();
        }
        long long query() const{
            return sumLow;
        }
    };
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        k -= 1;
        SmartWindow window(k);
        for(int i = 1; i <= 1 + dist; i ++){
            window.add(nums[i]);
        }
        long long ans = window.query();
        for(int i = 2; i + dist < n; i ++){
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);
            ans = min(ans, window.query());
        }
        return ans + nums[0];
    }
};