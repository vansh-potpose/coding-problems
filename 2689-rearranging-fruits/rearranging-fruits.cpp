class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        map<int, int> total;

        for (int num : basket1) {
            freq[num]++;
            total[num]++;
        }
        for (int num : basket2) {
            freq[num]--;
            total[num]++;
        }

        for (auto [num, count] : total) {
            if (count % 2 != 0) return -1;
        }

        vector<int> excess;

        for (auto [num, count] : freq) {
            if (count != 0) {
                int half = abs(count) / 2;
                for (int i = 0; i < half; ++i)
                    excess.push_back(num);
            }
        }

        sort(excess.begin(), excess.end());
        int n = excess.size();

        int min_elem = min(*min_element(basket1.begin(), basket1.end()),
                       *min_element(basket2.begin(), basket2.end()));


        long long cost = 0;
        for (int i = 0; i < n / 2; ++i) {
            cost += min((long long)excess[i], 2LL * min_elem);
        }

        return cost;

    }
};