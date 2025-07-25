class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> mp(201,0);
        int sum=INT_MIN;
        for(int n : nums){
            if(mp[n+100]==0){
                mp[n+100]++;
            }
        }

        for(int i=100;i>=-100;i--){
            if(mp[i+100]){
                if(sum==INT_MIN){
                    sum=i;
                }else if(i>0){
                    sum+=i;
                }
            }
        }

        return sum;
    }
};