#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };
        
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int curr = roman[s[i]];
            int next = (i+1 < s.size()) ? roman[s[i+1]] : 0;
            
            if (curr < next) {
                result -= curr;
            } else {
                result += curr;
            }
        }
        return result;
    }
};