class Solution {
private:
    vector<int> nums;
public:
    TreeNode* balanceBST(TreeNode* root) {
        nums.clear();
        getNumbers(root);
        return balanceTree(0, nums.size() - 1);
    }
private:
    void getNumbers(TreeNode* node) {
        if (node == nullptr) return;
        getNumbers(node->left);
        nums.push_back(node->val);
        getNumbers(node->right);
    }
    TreeNode* balanceTree(int l, int r) {
        if (l > r) return nullptr;
        int middleIdx = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[middleIdx]);
        root->left = balanceTree(l, middleIdx - 1);
        root->right = balanceTree(middleIdx + 1, r);
        return root;
    }
};