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
    TreeNode* generateBST(int n, int start, int end, vector<int> &preorder) {
        TreeNode* root = new TreeNode(preorder[start]);
        if (end - start == 0 ) return root;

        int mid = end;
        for (int i = start + 1; i < n; i++) {
            if (preorder[start] < preorder[i]) { 
                mid = i - 1;
                break;
            }
        }

        if (start+1 <= mid) root->left  = generateBST(n, start+1, mid, preorder);
        if (mid+1 <= end)   root->right = generateBST(n, mid+1, end, preorder);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        return generateBST(n, 0, n-1, preorder);
    }
};