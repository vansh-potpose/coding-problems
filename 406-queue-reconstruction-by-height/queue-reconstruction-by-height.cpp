class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];  // sort by height descending
            return a[1] < b[1];                   // sort by k ascending
        });

        vector<vector<int>> result;
        for (auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};
