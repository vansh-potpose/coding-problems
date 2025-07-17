class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0 ;
        for(int i=0 ; i<nums.size() ; i++){
            nums[i] = nums[i]%k ;
        }
        int n = nums.size() ;
        for(int val=0 ; val<k ; val++){
            vector<int> v(k) ;
            v[nums[0]] = 1 ;
            for(int i=1 ; i<n ; i++){
                int a = nums[i] ;
                int b = (val-a+k)%k ;
                v[nums[i]] = 1+v[b] ;
                ans = max(ans , v[nums[i]]) ;
            }
        }   
        return ans ;
    }
};