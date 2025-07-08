class Solution {
public:

    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        char delimiter=' ';
        string result="";
        
        while (getline(ss, token, delimiter)) {
            if (!token.empty()) {
                if(result.empty()){
                    result=token;
                }else{
                result=token + " "+result;
                }
            }
        }
        return result;
    }
};