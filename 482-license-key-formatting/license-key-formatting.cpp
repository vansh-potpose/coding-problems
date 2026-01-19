class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cur=k;
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='-') continue;
            if(cur==0){
                cur=k;
                ans.push_back('-');
            }
            ans.push_back(toupper(s[i]));
            cur--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};