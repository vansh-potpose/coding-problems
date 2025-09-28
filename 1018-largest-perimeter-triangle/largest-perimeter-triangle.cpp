class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for( int i = nums.size()-1; i>=0; i--){
            if( i-2>=0 && i-1>=0){
                if( nums[i-2]+ nums[i-1]>nums[i]){
                    return nums[i-2]+ nums[i-1]+ nums[i];
                }
            }
        }
        return 0;
    }
};