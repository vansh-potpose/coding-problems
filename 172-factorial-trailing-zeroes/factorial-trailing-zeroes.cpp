class Solution {
public:
    int trailingZeroes(int n) {
        if (n <= 4) return 0;
        int count = 0;
        for (long long i = 5; n/i>0; i*=5) {
            count += n/i;
        }
        return count;
    }
};