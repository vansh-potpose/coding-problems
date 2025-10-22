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
class BSTIterator {
    stack<TreeNode*> inorderSuccessors;

public:
    BSTIterator(TreeNode* root) {
        while (root) {
            inorderSuccessors.push(root);
            root = root->left;
        }

        inorderSuccessors.push(nullptr);   
    }

    int next(){

        TreeNode *currNode = inorderSuccessors.top();
        inorderSuccessors.pop();

        if(currNode == nullptr) return inorderSuccessors.top()->val;
        else if(currNode->right == nullptr) return inorderSuccessors.top()->val;
        // else: get the successor in the stack and also the possible succesor of subtrees

        TreeNode* successor = currNode->right;
        while(successor){
            inorderSuccessors.push(successor);
            successor = successor->left;
        }
        return  inorderSuccessors.top()->val;
    }

    bool hasNext() {

        if(inorderSuccessors.empty()) return false;
        else if(inorderSuccessors.size() > 1) return true;
        else return  inorderSuccessors.top()->right != nullptr;  
        // if there is only one node, then it must have the successor node, i.e  atleast one node in the right subtree
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */