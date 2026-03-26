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
    int solve(TreeNode *node) {
        if (node == nullptr) return 0;

        // Left depth
        int leftDepth = 0;
        if (node->left != nullptr) {
            leftDepth = solve(node->left);
        }

        // Right depth
        int rightDepth = 0;
        if (node->right != nullptr) {
            rightDepth = solve(node->right);
        }

        return 1 + max(leftDepth, rightDepth);
    }
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};