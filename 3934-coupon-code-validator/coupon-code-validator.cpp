class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, vector<string>> m;
        int n = code.size();
        for (int i = 0; i < n; i++)
        {
            bool flag = isActive[i] && (businessLine[i] == "electronics" || 
            businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || 
            businessLine[i] == "restaurant") && code[i].size() > 0;
            if (flag)
            {
                for (auto& c : code[i])
                    if (!(isalpha(c) || isdigit(c) || c == '_'))
                    {
                        flag = false;
                        break;
                    }
            }
            if (flag)
                m[businessLine[i]].push_back(code[i]);
        }
        vector<string> cats = {"electronics", "grocery", "pharmacy", "restaurant"}; 
        vector<string> ans;
        for (auto& cat : cats)
        {
            sort(m[cat].begin(), m[cat].end());
            for (auto& coupon : m[cat])
                ans.push_back(coupon);
        }
        return ans;
    }
};