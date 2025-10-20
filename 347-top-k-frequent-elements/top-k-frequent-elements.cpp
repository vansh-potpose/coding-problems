class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    int n = nums.size();
    
    vector<vector<int>> idx(n + 1);

   
    for (auto &it : freq) {
        idx[it.second].push_back(it.first);
    }

    vector<int> ans;
   
    for (int i = n; i >= 0 && ans.size() < k; i--) {
        for (int num : idx[i]) {
            ans.push_back(num);
            if (ans.size() == k) break;
        }
    }

    return ans;
    }
};