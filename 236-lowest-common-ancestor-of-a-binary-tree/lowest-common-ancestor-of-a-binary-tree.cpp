/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* ancestors(TreeNode* node, TreeNode* x, TreeNode* y) {
        if (!node) return nullptr;
        if (node == x) return x;
        if (node == y) return y;

        TreeNode* cond1 = ancestors(node->left, x, y);
        TreeNode* cond2 = ancestors(node->right, x, y);

        if (cond1 && cond2)  return node;
        if (cond1 && !cond2) return cond1;
        if (!cond1 && cond2) return cond2;

        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ancestors(root, p, q);
    }
};