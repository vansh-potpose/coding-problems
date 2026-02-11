/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};

        vector<int> ans;

        stack<pair<Node*, bool>> st;
        st.push({root, false});

        while(!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if(visited) {
                ans.push_back(node->val);
            } else {
                st.push({node, true});
                
                for(int i=node->children.size()-1; i>=0; i--) {
                    st.push({node->children[i], false});
                }
            }
        }

        return ans;
    }
};