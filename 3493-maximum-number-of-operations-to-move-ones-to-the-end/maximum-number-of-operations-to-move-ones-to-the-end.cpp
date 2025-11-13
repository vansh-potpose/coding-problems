class Solution {
public:
    int maxOperations(string s) {
        int cnt=0;
        int maxOpr=0;
        for(int i =0;i<s.size()-1;i++){
            if(s[i]=='1'){
                cnt++;
                if(s[i+1]=='0'){
                    maxOpr+=cnt;
                    while(s[i+1]=='0' && i+1<s.size()){
                        i++;
                    }
                }
            }
        }
        return maxOpr;
    }
};