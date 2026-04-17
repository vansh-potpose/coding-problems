class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& a) {
        unordered_map<int, int> mpp;
        int n = a.size(), ans = 1e6;

        for (int i = 0; i < n; i++) {
            if (mpp.count(a[i])) {
                ans = min(ans, i - mpp[a[i]]);
            }
            mpp[reverse(a[i])] = i;
        }
        return ans == 1e6 ? -1 : ans;
    }
};