class Solution {
public:
    int calculate(string s) {
        int result = 0, sign = 1, num = 0;
        stack<int> st; // stores previous results and signs

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                // push current result and sign for the new context
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop();   // apply sign before '('
                result += st.top(); st.pop();   // add result before '('
            }
            // ignore whitespace
        }

        return result + sign * num; // in case something like "3 + 2"
    }
};
