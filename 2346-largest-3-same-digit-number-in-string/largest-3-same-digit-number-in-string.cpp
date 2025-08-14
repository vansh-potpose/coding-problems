class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi=-1;
        string str="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]-'0'>maxi && (num[i+1]==num[i] && num[i+2]==num[i])){
                str=num.substr(i,3);
                maxi=num[i]-'0';
            }
        }
        return str;
    }
};