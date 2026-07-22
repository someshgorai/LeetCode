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
    int getPathSum(TreeNode* node, int &maxSum) {
        if (!node) return 0;

        int leftSum = max(0, getPathSum(node->left, maxSum));
        int rightSum = max(0, getPathSum(node->right, maxSum));

        maxSum = max(maxSum, leftSum + rightSum + node->val);

        return max(leftSum, rightSum) + node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = -1e3;
        getPathSum(root, maxSum);
        return maxSum;
    }
};