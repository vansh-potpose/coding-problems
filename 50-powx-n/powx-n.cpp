class Solution {
public:
    long double oddPow(long double x,int n){
        if(n==1)
        return x;
        else if(n>0)
        return x*evenPow(x,n-1);
        else if(n==-1)
        return 1/x;
        else if(n<0)
        return 1/x*evenPow(x,n+1);
        return 1;
    }
    long double evenPow(long double x,int n){
        if(n==1)
        return x;
        else if(n%2!=0)
        return oddPow(x,n);
        else if(n>0){
            long double half= evenPow(x,n/2);
        return half*half;
        }
        else if(n==-1)
        return 1/x;
        else if(n<0){
            long double half=evenPow(x,n/2);
        return half*half;
        }
        return 1;
    }
    long double myPow(long double x, int n) {
        if(n==0)
        return 1;
        else if(x==1 || x==0)
        return x;
        else if(n%2==0)
        return evenPow(x,n);
        else if(n%2!=0)
        return oddPow(x,n);
        return -1;
    }
};