#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;  // the smallest number we can't form yet
        int i = 0, patches = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                // Patch in 'miss' itself
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
};
