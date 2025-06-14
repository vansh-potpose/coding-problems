#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper: Get max subsequence of length k from nums
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!res.empty() && res.back() < num && drop > 0) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    // Helper: Merge two sequences to get max lexicographical sequence
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> merged;
        auto i = a.begin(), j = b.begin();
        while (i != a.end() || j != b.end()) {
            if (lexicographical_compare(i, a.end(), j, b.end()))
                merged.push_back(*j++);
            else
                merged.push_back(*i++);
        }
        return merged;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            vector<int> subseq1 = maxSubsequence(nums1, i);
            vector<int> subseq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subseq1, subseq2);
            best = max(best, candidate);
        }
        return best;
    }
};
