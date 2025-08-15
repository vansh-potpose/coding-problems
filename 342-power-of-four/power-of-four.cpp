class Solution {
public:
    bool isPowerOfFour(int n) {
        int count=0;
        bool canPower=false;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                count++;
                if(i%2==0){
                    canPower=true;
                }
            }
        }

        return count==1?canPower:false;
    }
};