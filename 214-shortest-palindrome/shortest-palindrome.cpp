class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                left++;
            }
        }
        if (left == length) {
            return s;
        }
        string nonPalindromeSuffix = s.substr(left);

        string reverseSuffix = string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        return reverseSuffix + shortestPalindrome(s.substr(0, left)) + nonPalindromeSuffix;
    }
};