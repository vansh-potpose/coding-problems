class Solution {
public:
    string reverseVowels(string s) {
        string str = "aeiouAEIOU";
        vector<char> temp;
        for(int i=0;i<s.size();i++){
            if(str.find(s[i])!=string::npos){
                temp.push_back(s[i]);
            }
        }
        int j=temp.size()-1;
        for(int i=0;i<s.size();i++){
            if(str.find(s[i])!=string::npos){
                s[i]=temp[j];
                j--;
            }
        }
        return s;
    }
};