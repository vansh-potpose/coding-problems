#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            if (found) continue; // Don't go deeper after finding valid strings

            for (int i = 0; i < current.length(); ++i) {
                if (current[i] != '(' && current[i] != ')') continue;

                string next = current.substr(0, i) + current.substr(i + 1);
                if (visited.count(next) == 0) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return result;
    }

private:
    bool isValid(const string &s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};
