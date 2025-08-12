class Solution {
public:
    const int MOD = 1000000007;
    
    // Modular exponentiation
    long long modpow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    // Convert n to list of powers of two
    vector<int> getNum(int n) {
        vector<int> num;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                num.push_back(1 << i);
            }
        }
        return num;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> num = getNum(n);
        
        // Prefix products
        vector<long long> prefix_prod(num.size());
        prefix_prod[0] = num[0] % MOD;
        for (int i = 1; i < num.size(); i++) {
            prefix_prod[i] = (prefix_prod[i-1] * num[i]) % MOD;
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back(prefix_prod[r]);
            } else {
                long long numerator = prefix_prod[r];
                long long denominator = prefix_prod[l-1];
                long long inverse = modpow(denominator, MOD - 2);
                ans.push_back((numerator * inverse) % MOD);
            }
        }
        return ans;
    }
};
