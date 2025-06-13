#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left; // max heap (smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // min heap (larger half)

public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance sizes: left can have at most one more element
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
