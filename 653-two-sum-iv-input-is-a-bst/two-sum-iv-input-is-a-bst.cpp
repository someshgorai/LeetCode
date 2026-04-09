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
    stack<TreeNode*> stBefore;
    stack<TreeNode*> stAfter;
    void storeBefore(TreeNode* root) {
        while (root) {
            stBefore.push(root);
            root = root->right;
        }
    }
    void storeAfter(TreeNode* root) {
        while (root) {
            stAfter.push(root);
            root = root->left;
        }
    }
    int before() {
        TreeNode* node = stBefore.top();
        stBefore.pop();
        if (node->left) storeBefore(node->left);
        return node->val;
    }
    int after() {
        TreeNode* node = stAfter.top();
        stAfter.pop();
        if (node->right) storeAfter(node->right);
        return node->val;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        storeAfter(root);
        storeBefore(root);
        int low = after();
        int high = before();
        while (low < high) {
            int sum = low + high;
            if (sum > k) {
                high = before();
            }
            else if (sum < k) {
                low = after();
            }
            else {
                return true;
            }
        }
        return false;
    }
};