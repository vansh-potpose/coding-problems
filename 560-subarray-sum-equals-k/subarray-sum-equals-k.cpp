class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};