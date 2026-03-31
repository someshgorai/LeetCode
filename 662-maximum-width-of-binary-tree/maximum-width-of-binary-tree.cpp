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
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, ll>> vis;
        vis.push({root, 0});

        int maxWidth = 1;

        while (!vis.empty()) {
            int n = vis.size();
            ll start = vis.front().second;
            int first, last;    

            for (int i = 0; i < n; i++) {
                auto [node, index] = vis.front();
                vis.pop();

                index -= start;

                if (i == 0)     first = index;
                if (i == n - 1) last  = index;

                if (node->left)  vis.push({node->left, 2*index + 1});
                if (node->right) vis.push({node->right, 2*index + 2});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};