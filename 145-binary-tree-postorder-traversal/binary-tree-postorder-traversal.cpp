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
        stack<TreeNode*> st1;
        vector<int> order;
        if (root == nullptr) return order;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* node = st1.top();
            order.push_back(node->val);
            st1.pop();
            if (node->left != nullptr) st1.push(node->left);
            if (node->right != nullptr) st1.push(node->right);
        }
        
        reverse(order.begin(), order.end());

        return order;
    }
};