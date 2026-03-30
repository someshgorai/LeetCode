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
private:
    void rightView(TreeNode* node, vector<int> &order, int level) {
        if (level == order.size()) order.push_back(node->val);

        if (node->right) rightView(node->right, order, level + 1);
        if (node->left)  rightView(node->left, order, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> order;
        if (!root) return order;

        rightView(root, order, 0);

        return order;
    }
};