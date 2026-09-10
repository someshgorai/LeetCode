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
    pair<int, int> getSubTreeSum(TreeNode* root, int& cnt) {
        if (root == nullptr) return {0, 0};

        auto [leftSubTreeSum, leftCnt]   = getSubTreeSum(root->left, cnt);
        auto [rightSubTreeSum, rightCnt] = getSubTreeSum(root->right, cnt);

        long long sum = (leftSubTreeSum + rightSubTreeSum + root->val);
        long long n   = (leftCnt + rightCnt + 1);
        int avg = (int)(sum / n);

        if (root->val == avg) {
            cnt++;
        }

        return {sum, n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;

        getSubTreeSum(root, cnt);

        return cnt;
    }
};