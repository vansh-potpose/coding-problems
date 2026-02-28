class Solution {
public:
    const int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        long result = 0;
        for (int i = 1; i <= n; ++i) {
            result = ((result << (std::bit_width((unsigned)i))) | i) % mod;
        }
        return result;
    }
};