class Solution {
public:
    int sym(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }

    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1 || sym(s[i]) >= sym(s[i + 1])) {
                ans += sym(s[i]);
            } else {
                ans -= sym(s[i]);
            }
        }
        return ans;
    }
};