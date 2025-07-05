class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int result=-1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto m : mp){
            if(m.second==m.first && m.first>result){
                result=m.first;
            }
        }

        return result;
    }
};