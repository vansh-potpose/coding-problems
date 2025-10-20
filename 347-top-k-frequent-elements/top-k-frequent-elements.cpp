class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        vector<pair<int, int>> pairs;
        vector<int> answear;

        for (auto i : freq) 
            pairs.push_back({i.first, i.second});

        sort(pairs.begin(), pairs.end(), [](pair<int,int>&a, pair<int,int>&b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++) 
            answear.push_back(pairs[i].first);

        return answear;
    }
};