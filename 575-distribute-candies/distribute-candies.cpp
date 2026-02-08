class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candytype;
        for(int i=0;i<candyType.size();i++){
            if(candytype.find(candyType[i])==candytype.end()){
                candytype.insert(candyType[i]);
            }
        }
        return min(candyType.size()/2,candytype.size());
    }
};