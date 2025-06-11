class Solution {
public:
    void findLps(string str, vector<int>&lps){
        int pref=0, suff=1;
        while(suff < str.length()){
            if(str[pref] == str[suff]){
                lps[suff]= pref+1;
                pref++;
                suff++;
            }
            else{   //not match
                if(pref==0)
                    suff++;
                else{
                    pref=lps[pref-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        string str= s+"$" +rev;
        vector<int> lps(str.length(),0);
        findLps(str, lps);
        int palindromeLen=lps[str.length()-1];
        rev="";
        for(int i=s.length()-1;i>=palindromeLen;i--){
            rev+=s[i];
        }
        rev+=s;
        return rev;

    }
};

