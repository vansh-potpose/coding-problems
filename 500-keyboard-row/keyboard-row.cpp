class Solution {
public:
    bool check(string &s, string &c){
        for(int i=0;i<c.size();i++){
            if(s.find(tolower(c[i])) == string::npos){
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        string firstRow="qwertyuiop";
        string secondRow="asdfghjkl";
        string thirdRow="zxcvbnm";
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(firstRow.find(tolower(words[i][0])) != string::npos){
                if(check(firstRow,words[i])){
                    res.push_back(words[i]);
                }
            }else if(secondRow.find(tolower(words[i][0])) != string::npos){
                if(check(secondRow,words[i])){
                    res.push_back(words[i]);
                }
            }else{
                if(check(thirdRow,words[i])){
                    res.push_back(words[i]);
                }
            }
        }
        return res;
    }
};