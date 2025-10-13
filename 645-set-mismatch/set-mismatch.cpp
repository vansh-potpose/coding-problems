class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long a = n*(n+1)>>1;
        long b = a*((n<<1)+1)/3;
        for (int i : nums) {a -= i; b -= i*i;}
        return {static_cast<int>((b-a*a)/a/2), static_cast<int>((b+a*a)/a/2)};
    }
};