class Solution {
    vector<int> v;

    void levelSum(int lvl, TreeNode* root) {
        if (!root) return;

        if (v.size() == lvl)
            v.push_back(root->val);
        else
            v[lvl] += root->val;

        levelSum(lvl + 1, root->left);
        levelSum(lvl + 1, root->right);
    }

public:
    int maxLevelSum(TreeNode* root) {
        levelSum(0, root);

        int maxSum = v[0];
        int level = 1;  // 1-based indexing

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > maxSum) {
                maxSum = v[i];
                level = i + 1;
            }
        }
        return level;
    }
};
