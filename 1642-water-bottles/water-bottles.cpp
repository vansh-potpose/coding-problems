class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=0;
        int emptyB=0;
        while(numBottles>0){
            total+=numBottles;
            emptyB+=numBottles;
            numBottles=0;
            numBottles+=emptyB/numExchange;
            emptyB=emptyB%numExchange;
        }
        return total;
    }
};