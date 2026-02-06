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
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        int ans = leftSum + rightSum + root->val;
        root->val = abs(leftSum - rightSum);
        return ans;
    }
    int findSum(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = findSum(root->left);
        int rightSum = findSum(root->right);
        int ans = leftSum + rightSum + root->val;
        return ans;
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return findSum(root);
    }
};