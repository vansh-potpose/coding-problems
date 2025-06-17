class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();

        // Fix two rows
        for (int top = 0; top < m; ++top) {
            vector<int> colSum(n, 0); // Compressed 1D array
            for (int bottom = top; bottom < m; ++bottom) {
                // Update colSum between rows [top...bottom]
                for (int j = 0; j < n; ++j)
                    colSum[j] += matrix[bottom][j];

                // Use TreeSet (set) to store prefix sums
                set<int> prefixSums = {0};
                int sum = 0;

                for (int val : colSum) {
                    sum += val;
                    auto it = prefixSums.lower_bound(sum - k);
                    if (it != prefixSums.end())
                        maxSum = max(maxSum, sum - *it);
                    prefixSums.insert(sum);
                }
            }
        }

        return maxSum;
    }
};