class Solution {
public:
    int totalMoney(int n) {
        vector<int> days_money={0,1,3,6,10,15,21};
        int weeks=n/7;
        int rem_days=n%7;
        int total= 28*weeks+7*(weeks*(weeks-1))/2;
        total+= (rem_days*(rem_days+1))/2 + rem_days*weeks;

        return total;
    }
};