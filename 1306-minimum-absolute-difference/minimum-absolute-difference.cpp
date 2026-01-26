class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];

            if (diff < minDiff) {
                minDiff = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            } 
            else if (diff == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};
