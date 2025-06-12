class NumArray {
private:
    vector<int> tree;
    int n;

    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        }else{
            int mid = (start + end) / 2;
            buildTree(nums, 2*node+1, start, mid);
            buildTree(nums, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                updateTree(2*node+1, start, mid, idx, val);
            else
                updateTree(2*node+2, mid+1, end, idx, val);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) +
               query(2*node+2, mid+1, end, l, r);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, 0, n-1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};
