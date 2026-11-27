class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twice=0;
        for(int num : nums){
            ones=(ones^num) & ~twice;
            twice=(twice^num)& ~ones;
        }
        return ones;
    }
};