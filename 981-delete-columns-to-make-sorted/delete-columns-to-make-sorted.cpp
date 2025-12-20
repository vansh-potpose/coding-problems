class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> strs_i(strs[0].size(),0);
        int count=0;
        for(string str:strs){
            for(int i=0;i<strs_i.size();i++){
                if(strs_i[i]!=-1){
                    if(str[i]-'a'<strs_i[i]){
                        strs_i[i]=-1;
                        count++;
                    }else{
                        strs_i[i]=str[i]-'a';
                    }
                }
            }
        }
       
        return count;
    }
};