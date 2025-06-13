class Solution {
public:
    vector<string> result;

    void backtrack(string& num, int target, int pos, long eval, long prev, string expr) {
        if (pos == num.size()) {
            if (eval == target) result.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break; // prevent numbers with leading zero

            string currStr = num.substr(pos, i - pos + 1);
            long curr = stol(currStr);

            if (pos == 0) {
                // First number, no operator
                backtrack(num, target, i + 1, curr, curr, currStr);
            } else {
                backtrack(num, target, i + 1, eval + curr, curr, expr + "+" + currStr);
                backtrack(num, target, i + 1, eval - curr, -curr, expr + "-" + currStr);
                // For multiplication, subtract prev and add (prev * curr)
                backtrack(num, target, i + 1, eval - prev + prev * curr, prev * curr, expr + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        if (num.empty()) return result;
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
