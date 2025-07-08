class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str, ans = "";
        while (ss>>str) {
            reverse(str.begin(), str.end());
            ans += str + " ";
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};