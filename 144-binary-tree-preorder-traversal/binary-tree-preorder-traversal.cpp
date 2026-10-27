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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == nullptr) {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* next = curr->left;
                while (next->right && next->right != curr) {
                    next = next->right;
                } 

                if (next->right == nullptr) {
                    next->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    next->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};