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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> vis;
        map<int, int> order;

        if (!root) return {};

        vis.push({root, 0});

        while (!vis.empty()) {
            auto point = vis.front();
            vis.pop();

            TreeNode* node = point.first;
            int level = point.second; 

            order[level] = node->val;

            if (node->left)  vis.push({node->left, level + 1});
            if (node->right) vis.push({node->right, level + 1});
        }

        vector<int> rightOrder;
        for (auto p : order) {
            rightOrder.push_back(p.second);
        }

        return rightOrder;
    }
};