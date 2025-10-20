class Solution {
public:
    int isPossible(vector<int>& arr, int mid) {
        int count = 1;
        long long CurrentSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] + CurrentSum <= mid) {
                CurrentSum += arr[i];
            } else {
                count++;
                CurrentSum = arr[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};