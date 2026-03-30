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
    bool traversal(TreeNode* curr1, TreeNode* curr2) {
        if (!curr1 && !curr2) return true;

        if (!curr1 || !curr2) return false;

        if (curr1->val != curr2->val) return false;

        if (!traversal(curr1->left, curr2->right)) return false;
        if (!traversal(curr1->right, curr2->left)) return false;

        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        if (root->left == nullptr && root->right == nullptr) return true;

        if (root->left == nullptr || root->right == nullptr) return false;

        return traversal(root->left, root->right);
    }   
};