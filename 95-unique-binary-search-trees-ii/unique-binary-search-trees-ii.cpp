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
    vector<TreeNode*> generate(int l,int r){
        
        if (l > r) {
            return {NULL};
        }
        vector<TreeNode*> trees;

        for(int i=l;i<=r;i++){
            vector<TreeNode*> leftTrees=generate(l,i-1);
            vector<TreeNode*> rightTrees=generate(i+1,r);

            for(TreeNode* left:leftTrees){
                for(TreeNode* right:rightTrees){
                    trees.emplace_back(new TreeNode(i, left, right));
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};