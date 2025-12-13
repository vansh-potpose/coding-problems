class Solution {
    bool isAlphanumericOrUnderscore(const std::string& str) {
    if(!str.size()) return false;
    return all_of(str.begin(), str.end(), [](unsigned char c) {
        return isalnum(c) || c == '_';
    });
}
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> temp;
        unordered_set<string> b={"electronics", "grocery", "pharmacy", "restaurant"};

        for(int i=0;i<code.size();i++){
            if(isActive[i] && b.count(businessLine[i]) && isAlphanumericOrUnderscore(code[i])){
                temp.push_back({code[i],businessLine[i]});
            }
        }

        sort(temp.begin(),temp.end(),[](const pair<string,string> & a,const pair<string,string> & b){
            if(a.second==b.second){
                return a.first<b.first;
            }else{
                return a.second<b.second;
            }
        });


        vector<string> result;
        for(int i=0;i<temp.size();i++){
            result.push_back(temp[i].first);
        }
        return result;
    }
};