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
    int solve(TreeNode* node, int &maxPathSum) {
        if (node == nullptr) return 0;

        int leftSum = max(0, solve(node->left, maxPathSum));
        int rightSum = max(0, solve(node->right, maxPathSum));

        int nodeValue = node->val;

        // Case: path passing through current node
        int currentPath = nodeValue + leftSum + rightSum;

        // Update global maximum
        maxPathSum = max(maxPathSum, currentPath);

        // Return best single path (no split)
        return nodeValue + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;   // important fix
        solve(root, maxPathSum);
        return maxPathSum;
    }
};