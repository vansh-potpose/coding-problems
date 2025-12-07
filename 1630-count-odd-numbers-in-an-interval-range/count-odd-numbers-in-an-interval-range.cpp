class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        if(low%2){
            count++;
            low++;
        }
        if(high%2){
            count++;
            high--;
        }

        count+=(high-low)/2;
        return count;
    }
};