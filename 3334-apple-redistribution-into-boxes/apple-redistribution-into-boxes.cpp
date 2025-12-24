class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum;
        sum=accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int count=0;
        for(int &i:capacity){
            if(sum<=0)break;
            sum-=i;
            count++;
        }
        return count;

    }
};