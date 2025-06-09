class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

    vector<string> dfs(string s){
        if(memo.count(s)) return memo[s];

        vector<string> res;

        if(dict.count(s)) res.push_back(s);

        for(int i=1;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i);

            if (dict.count(left)) {
                vector<string> sublist = dfs(right);
                for (string sub : sublist) {
                    res.push_back(left + " " + sub);
                }
            }
        }
        return memo[s]=res;
    }
};