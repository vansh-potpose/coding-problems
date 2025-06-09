class Solution {
    unordered_set<string> wordSet;
    vector<string> res;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> cur;
        wordSet = unordered_set<string> (wordDict.begin(), wordDict.end());
        rec(s,0,cur);
        return res;
    }

    void rec (const string &s, int index, vector<string> &cur) {
        if (index == s.length()){
            res.push_back(join(cur));
            return;
        } 
        for (int j = index; j<s.length(); j++) {
            string w = s.substr(index, j-index+1);
            if (wordSet.count(w)) {
                cur.push_back(w);
                rec(s, j+1, cur);
                cur.pop_back();
            }
        }
    }

    string join(const vector<string> &cur) {
        ostringstream oss;
        for (int i = 0; i<cur.size(); i++) {
            if (i!=0) oss << " ";
            oss << cur[i];
        }
        return oss.str();
    }
};