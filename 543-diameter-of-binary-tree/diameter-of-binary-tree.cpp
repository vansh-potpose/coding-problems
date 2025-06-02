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
    int maxDiameter = 0;

    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // Update max diameter at each node
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};
