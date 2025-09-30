class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(nums);

        while(temp.size()>1){
            vector<int> temp1;
            for(int j=0;j<temp.size()-1;j++){
                temp1.push_back((temp[j]+temp[j+1])%10);
            }
            temp=temp1;
        }
        return temp[0];
    }
};