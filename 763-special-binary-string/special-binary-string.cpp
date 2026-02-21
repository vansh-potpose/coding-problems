class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> res;
        
        for (int j = 0; j < s.length(); j++) {
            // Track balance: +1 for '1', -1 for '0'
            count += (s[j] == '1') ? 1 : -1;
            
            // Found a balanced chunk when count returns to 0
            if (count == 0) {
                // Recursively maximize inner part, wrap with 1...0
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1; // Move to next potential chunk
            }
        }
        
        // Sort chunks in descending order for largest arrangement
        sort(res.begin(), res.end(), greater<string>());
        
        string result;
        for (const string& str : res) {
            result += str;
        }
        return result;
    }
};