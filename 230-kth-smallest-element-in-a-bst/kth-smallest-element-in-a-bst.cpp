/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

public:
    void calculation(TreeNode* root,
                     priority_queue<int, vector<int>, greater<int>>& pq) {
        if (root != NULL) {
            pq.push(root->val);
            calculation(root->left, pq);
            calculation(root->right, pq);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        calculation(root, pq);
        k -= 1;
        while (k--) {
            pq.pop();
        }
        return pq.top();
    }
};