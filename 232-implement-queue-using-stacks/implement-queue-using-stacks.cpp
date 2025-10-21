#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // input stack
    std::stack<int> s2; // output stack

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        shiftStacks();
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        shiftStacks();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    // Helper: move elements only if s2 is empty
    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};
