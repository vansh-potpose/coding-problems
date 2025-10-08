class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> result;
        for(int i=0;i<spells.size();i++){
            long long target=success/spells[i];
            if(success%spells[i]){
                target+=1;
            }
            auto itr= lower_bound(potions.begin(),potions.end(),target);
            int index= distance(potions.begin(),itr);
            result.push_back(potions.size()-index);
        }
        return result;
    }
};