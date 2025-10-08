class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n == 1) return res;
        for(int i = 1; i < n; ++i){
            int count = 1, m = res.length();
            string temp;
            temp.reserve(m * 2);
            for(int j = 0; j < m; ++j){
                if(j + 1 < m && res[j] == res[j + 1]) ++count;
                else{
                    temp += to_string(count);
                    temp.push_back(res[j]);
                    count = 1;
                }
            }
            res = move(temp);
        }
        return res;
    }
};