class Solution {
public:



    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        string prev=folder[0];
        res.push_back(prev);
        for(int i=1;i<folder.size();i++){
            if(prev==folder[i].substr(0,prev.size()) && folder[i][prev.size()]=='/'){
                continue;
            }else{
                prev=folder[i];
                res.push_back(prev);
            }
        }
        return res;
    }
};