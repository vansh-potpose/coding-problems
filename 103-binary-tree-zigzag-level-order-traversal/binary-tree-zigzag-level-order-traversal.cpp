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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        bool ltor = true;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int idx = ltor ? i : size - i - 1;
                ans[idx] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            result.push_back(ans);
            ltor = !ltor;
        }

        return result;
    }
};