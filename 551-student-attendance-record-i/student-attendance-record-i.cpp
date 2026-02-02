class Solution {
public:
    bool checkRecord(string s) {
        if(s.size()==0){
            return true;
        }
        if(s.size()==1){
            return true;
        }
        if(s.size()==2){
            if(s[0]==s[1] && s[0]!='A'){
                return true;
            }
        }
        unordered_map<char,int>um;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        if(um['A']>=2){
           return false;
        }
        if(um['L']<3){
            return true;
        }
        bool button =false;
        for(int i=0;i<s.size()-2;i++){
            if(s[i] == s[i+1] && s[i+1]==s[i+2] && s[i]=='L'){
                button= true;
            }
        }
        if(um['A']<2 && button == false){
            return true;
        }
       return false;
    }
};