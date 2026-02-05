class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& A) {
        int n = A.size(), bias = n * (99 / n) + n;
        
        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(A[(i + A[i] + bias) % n]);

        return res;
    }
};