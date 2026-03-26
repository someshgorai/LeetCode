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
    int maxi = 0;
    int solve(TreeNode* node) {
        // Base Case
        if (node == nullptr) return 0;

        int leftHeight = solve(node->left);

        int rightHeight = solve(node->right);

        maxi = max(maxi, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxi;
    }
};