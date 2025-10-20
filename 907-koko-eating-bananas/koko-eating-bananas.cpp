class Solution {
public:

    long long timeTaken(vector<int> piles, int perHrBanana){
        long long totalHrs = 0;

        for(long long banana : piles){
            totalHrs += ceil((double)banana/(double)perHrBanana);
        }

        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;

        while(low <= high){
            long long mid = low + (high - low)/2;

            long long k = timeTaken(piles, mid);

            if(k <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};