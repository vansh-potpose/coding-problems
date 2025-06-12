class SegmentTree {
private:
    vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int index) {
        if (start == end) {
            tree[node]++;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(2 * node, start, mid, index);
        else
            update(2 * node + 1, mid + 1, end, index);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        set<long> all_values;

        // Build prefix sum and collect possible values
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        for (long sum : prefix) {
            all_values.insert(sum);
            all_values.insert(sum - lower);
            all_values.insert(sum - upper);
        }

        // Coordinate compression
        unordered_map<long, int> valueToIndex;
        int id = 0;
        for (long val : all_values) {
            valueToIndex[val] = ++id;  // 1-based indexing
        }

        SegmentTree seg(id + 2);
        int count = 0;
        for (long sum : prefix) {
            int left = valueToIndex[sum - upper];
            int right = valueToIndex[sum - lower];
            count += seg.query(1, 1, id, left, right);
            seg.update(1, 1, id, valueToIndex[sum]);
        }

        return count;
    }
};
