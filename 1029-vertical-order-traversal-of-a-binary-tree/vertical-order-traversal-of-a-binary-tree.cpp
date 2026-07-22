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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {{}};
        queue<tuple<TreeNode*, int, int>> q;
        map<int, map<int, multiset<int>>> mpp;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, vlevel, hlevel] = q.front();
            mpp[vlevel][hlevel].insert(node->val);
            q.pop();
            if (node->left) q.push({node->left, vlevel-1, hlevel+1});
            if (node->right) q.push({node->right, vlevel+1, hlevel+1});
        } 

        vector<vector<int>> order;
        for (auto &ver : mpp) {
            vector<int> temp;
            for (auto &hor : ver.second) {
                temp.insert(temp.end(), hor.second.begin(), hor.second.end());
            }
            order.push_back(temp);
        }
        return order;
    }
};