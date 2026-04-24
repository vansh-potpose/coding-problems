class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x=0, r=0;
        for(char c: moves){
            switch(c){
                case 'R': x++; break;
                case 'L': x--; break;
                case '_': r++; break;
            }
        }
        return abs(x)+r;
    }
};