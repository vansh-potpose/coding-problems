class Solution {
public:
    bool checkPerfectNumber(int num) {
      if(num==1)return false;
      long long result=0;
      long long sqrtnum=sqrt(num);
      while(sqrtnum>1){
        if(num%sqrtnum==0){
            result+=sqrtnum;
            result+=num/sqrtnum;
        }
        sqrtnum--;
      }
       result++;
      if(result==num){
        return true;
      }
      return false;
      }
};