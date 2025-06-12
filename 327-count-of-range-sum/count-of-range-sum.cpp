class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        return countWhileMergeSort(prefix, 0, n + 1, lower, upper);
    }

private:
    int countWhileMergeSort(vector<long>& sum, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = countWhileMergeSort(sum, left, mid, lower, upper)
                  + countWhileMergeSort(sum, mid, right, lower, upper);
        
        int j = mid, k = mid, t = mid;
        vector<long> cache(right - left);
        int r = 0;

        for (int i = left; i < mid; ++i) {
            while (k < right && sum[k] - sum[i] < lower) k++;
            while (j < right && sum[j] - sum[i] <= upper) j++;
            while (t < right && sum[t] < sum[i]) cache[r++] = sum[t++];
            cache[r++] = sum[i];
            count += j - k;
        }
        copy(cache.begin(), cache.begin() + r, sum.begin() + left);
        return count;
    }
};
