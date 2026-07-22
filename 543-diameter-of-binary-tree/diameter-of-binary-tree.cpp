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
    int maxDiameter = 0;
    int getDiameter(TreeNode* node) {
        if (!node) return 0;

        int leftLength = getDiameter(node->left);
        int rightLength = getDiameter(node->right);

        maxDiameter = max(maxDiameter, leftLength + rightLength);

        return max(leftLength, rightLength) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return maxDiameter;
    }
};