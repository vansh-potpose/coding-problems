/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long long mod = 1e9 + 7;
long long total = 0;
long long ans = 0;

    long long subTreeSum(TreeNode* root) {
        if(root == NULL)    return 0;

        long long leftSum = subTreeSum(root->left);
        long long rightSum = subTreeSum(root->right);

        ans = max(ans, (leftSum * (total - leftSum)));
        ans = max(ans, (rightSum * (total - rightSum)));

        return leftSum + rightSum + root->val;
    }

    void totalSum(TreeNode* root) {
        if(root == NULL)    return;
        total += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum(root);
        subTreeSum(root);
        return ans % mod;
    }
};