class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node]++;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx);
        else
            update(2 * node + 1, mid + 1, end, idx);
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
    int reversePairs(vector<int>& nums) {
        vector<long> all_vals;
        for (int num : nums) {
            all_vals.push_back(num);
            all_vals.push_back((long)num * 2);
        }

        // Coordinate compression
        sort(all_vals.begin(), all_vals.end());
        all_vals.erase(unique(all_vals.begin(), all_vals.end()), all_vals.end());

        unordered_map<long, int> val_to_index;
        for (int i = 0; i < all_vals.size(); ++i)
            val_to_index[all_vals[i]] = i + 1;  // 1-based index

        SegmentTree seg(all_vals.size() + 2);
        int count = 0;

        // Traverse from right to left
        for (int i = nums.size() - 1; i >= 0; --i) {
            long half = (long)nums[i];
            int idx = lower_bound(all_vals.begin(), all_vals.end(), half) - all_vals.begin();
            // Count elements less than nums[i]
            count += seg.query(1, 1, all_vals.size(), 1, idx);
            seg.update(1, 1, all_vals.size(), val_to_index[2L * nums[i]]);
        }

        return count;
    }
};
