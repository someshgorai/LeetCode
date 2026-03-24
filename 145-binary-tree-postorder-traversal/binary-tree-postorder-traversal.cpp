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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1, st2;
        if (root == nullptr) return {};
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st2.push(node);
            st1.pop();
            if (node->left != nullptr) st1.push(node->left);
            if (node->right != nullptr) st1.push(node->right);
        }
        vector<int> order;
        while (!st2.empty()) {
            TreeNode* node = st2.top();
            st2.pop();
            order.push_back(node->val);
        }
        return order;
    }
};