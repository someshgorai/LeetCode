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
    int kthSmallest(TreeNode* root, int k) {
        int small = -1;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                if (st.empty()) break;
                root = st.top();
                k--;
                if (k == 0) return root->val;
                st.pop();
                root = root->right;
            }
        }
        return -1;
    }
};