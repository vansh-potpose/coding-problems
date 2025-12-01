class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
         long sumPower = 0;
        for (auto power : batteries)
            sumPower += power;
        long left = 1, right = sumPower / n;
        
        while (left < right){
            long target = right - (right - left) / 2;
            long extra = 0;
            
            for (int power : batteries)
                extra += power<=target?power:target;

            if (extra >= (long)(n * target))
                left = target;
            else
                right = target - 1;
        }
        return left;
    }
};