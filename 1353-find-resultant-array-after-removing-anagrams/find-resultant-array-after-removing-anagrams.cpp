class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> s;
        
        string temp=words[0];
        sort(temp.begin(),temp.end());
        s.push_back(words[0]);

        for(int i=1;i<words.size();i++){
            string str=words[i];
            sort(str.begin(),str.end());
            if(temp!=str){
                s.push_back(words[i]);
                temp=str;
            }
            
        }
        
        
        return s;
    }
};