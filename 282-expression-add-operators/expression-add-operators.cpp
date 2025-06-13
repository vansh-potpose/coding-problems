#include <vector>
#include <string>
using namespace std;

using ll = long long;

class Solution {
public:
    vector<string> addOperators(const string &num, int target) {
        vector<string> results;
        if (num.empty()) return results;

        string expr;
        expr.reserve(num.size() * 2); // Reserve space for expression growth
        dfs(num, target, 0, 0, 0, expr, results);
        return results;
    }

private:
    void dfs(const string &num,
             int target,
             int pos,
             ll curValue,
             ll lastOperand,
             string &expr,
             vector<string> &results) {
        
        int n = num.size();
        if (pos == n) {
            if (curValue == target) {
                results.push_back(expr);
            }
            return;
        }

        for (int i = pos; i < n; ++i) {
            if (i > pos && num[pos] == '0') break; // Skip leading zero numbers

            string_view part = string_view(num).substr(pos, i - pos + 1);
            ll value = stoll(string(part)); // Convert only once

            int prevLen = expr.size();

            if (pos == 0) {
                expr += string(part);
                dfs(num, target, i + 1, value, value, expr, results);
                expr.resize(prevLen);
            } else {
                // '+'
                expr += "+" + string(part);
                dfs(num, target, i + 1, curValue + value, value, expr, results);
                expr.resize(prevLen);

                // '-'
                expr += "-" + string(part);
                dfs(num, target, i + 1, curValue - value, -value, expr, results);
                expr.resize(prevLen);

                // '*'
                expr += "*" + string(part);
                ll newCurValue = curValue - lastOperand + lastOperand * value;
                ll newLastOperand = lastOperand * value;
                dfs(num, target, i + 1, newCurValue, newLastOperand, expr, results);
                expr.resize(prevLen);
            }
        }
    }
};
