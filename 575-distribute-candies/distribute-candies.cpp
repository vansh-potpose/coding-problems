class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bool typeSeen[200001] = {false};
        int uniqueTypeCount = 0;
        int maxCandies = candyType.size() / 2;
        for (int type : candyType) {
            if (!typeSeen[type + 100000]) {
                typeSeen[type + 100000] = true;
                uniqueTypeCount++;
                if (uniqueTypeCount >= maxCandies) {
                    return maxCandies;
                }
            }
        }
        return uniqueTypeCount;
    }
};