class Solution {
public:

    void solve(string& s, int& k,int index){
        if(index+k <= s.size()){
            reverse(s.begin()+index,s.begin()+(index+k));
        }
        if(index+k > s.size()){
            reverse(s.begin()+index,s.end());
        }
        if(index >= s.size()){
            return;
        }
        solve(s,k,index+(2*k));
    }

    string reverseStr(string s, int k) {
        int index = 0;
        solve(s,k,index);
        return s;
    }
};