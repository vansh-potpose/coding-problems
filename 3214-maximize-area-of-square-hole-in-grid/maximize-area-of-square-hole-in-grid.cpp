class Solution {
public:
    int findgap( vector<int> bars){
        sort(bars.begin(),bars.end());

        int count = 2, res = 2;
        for(int i=1;i<bars.size();i++){
            // consecutive bars
            if(bars[i-1] + 1 == bars[i]){
                count++;
            }
            else{
                count = 2;
            }
            res = max(count,res);
        }
        return res;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // find horizontal gap and vertical gap
        int gap = min(findgap(hBars),findgap(vBars));
        // for square take min of horizonal and vertical
        return gap * gap;
    }
};