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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> order;
        if (!root) return order;

        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            order.push_back(node->val);
            st.pop();

            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }

        return order;
    }
};