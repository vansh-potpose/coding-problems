class Solution {
public:

    int minSteps(int left,int right,int start){
        return min(abs(start-left)+(right-left),abs(start-right)+(right-left));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=0,sum=0,maxF=0;

        for(int r=0;r<fruits.size();r++){
            sum+=fruits[r][1];

            while(l<=r && minSteps(fruits[l][0],fruits[r][0],startPos) > k){
                sum-=fruits[l][1];
                l++;
            }
            maxF=max(maxF,sum);
        }

        return maxF;

    }
};