class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2,0);
        for(int i = sqrt(area); i>=1; i--){
           int j = area / i;
           if(area == i*j){
            ans[0] = j;
            ans[1] = i;
            break;
           }
        }
        return ans;
    }
};