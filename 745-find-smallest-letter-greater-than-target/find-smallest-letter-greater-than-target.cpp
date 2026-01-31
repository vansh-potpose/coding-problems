class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=upper_bound(letters.begin(), letters.end(), target)-letters.begin();
        return (i==letters.size())?letters[0]:letters[i];
    }
};