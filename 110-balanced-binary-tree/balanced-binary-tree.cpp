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
    int balance(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int a=balance(root->left);
        int b=balance(root->right);
        if(abs(a-b)>1)return -1;
        if(a==-1 || b==-1)return -1;

        return max(a,b)+1;
    }
    bool isBalanced(TreeNode* root) {
        
        
        
        return balance(root)!=-1;
    }
};