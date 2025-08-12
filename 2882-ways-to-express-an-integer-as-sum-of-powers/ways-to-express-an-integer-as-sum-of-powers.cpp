class Solution {
public:
    int numberOfWays(int n, int exponent) {
        vector<int> dynamic(n + 1, 0);
        dynamic[0] = 1;
        int base = 1, power = 1;
        while (power <= n) {
            for (int index = n; index >= power; index--) {
                dynamic[index] = (dynamic[index] + dynamic[index - power]) % 1000000007;
            }
            ++base, power = fast_power(base, exponent);
        }
        return dynamic[n];
    }
    int fast_power(int base, int exponent) {
        int result = 1;
        while (exponent > 0) {
            if (exponent & 1) {
                result *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return result;
    }
};