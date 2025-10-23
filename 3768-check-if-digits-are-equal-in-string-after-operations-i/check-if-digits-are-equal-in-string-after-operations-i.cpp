class Solution {
public:
    char sumChar(char a, char b){
        int num =((a-'0') + (b-'0'))%10;
        return '0'+num;
    }
    bool hasSameDigits(string s) {

        while(s.size()>2){
            string new_str="";
            for(int i=0;i<s.size()-1;i++){
                new_str+=sumChar(s[i],s[i+1]);
            }
            s=new_str;
        }
        return s[0]==s[1];
    }
};