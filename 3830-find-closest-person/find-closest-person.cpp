class Solution {
public:
    int findClosest(int x, int y, int z) {
        int res=abs(z-x)-abs(z-y);
        if(res>0){
            return 2;
        }else if(res<0){
            return 1;
        }
        return 0;
    }
};