class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 0;
        queue<pair<TreeNode* , unsigned long long>> q;
        q.push({root , 0});
        while(!q.empty()){
            unsigned long long start = q.front().second, end = q.back().second;
            res = max(res , end - start + 1);
            for(int i = 0, n = q.size(); i < n; ++i){
                auto [node , pos] = q.front(); q.pop();
                unsigned long long idx = (pos - start) << 1; 
                if(node->left) q.push({node->left , idx + 1});
                if(node->right) q.push({node->right , idx + 2});
            }
        }
        return res;
    }
};