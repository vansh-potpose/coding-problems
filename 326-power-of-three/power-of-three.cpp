#include <bits/stdc++.h>
class Solution {
public:
    bool isPowerOfThree(int n) {
        int num = 0;
        for(int i = 0; pow(3,i) <= n; i++){
            num = pow(3,i);
            if(num == n) return true;
        }
        return false;
        // int i = 0;
        // do{
        //     i++;
        // }while(pow(3,i)<=n);

    }
};