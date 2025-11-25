class Solution {
public:
    int X[6]={1,11,111,1111,11111, 111111};

    int smallestRepunitDivByK(int k) {
        if((k&1)==0 || k%5==0) return -1;
        int len0=lower_bound(X,end(X),k)-X+1;
        int r=X[len0-1]%k;
        if(r==0)return len0;
        for(len0=len0+1;;len0++){
            r=(10*r+1)%k;
            if(r==0)return len0;
        }
        return -1;
    }
};