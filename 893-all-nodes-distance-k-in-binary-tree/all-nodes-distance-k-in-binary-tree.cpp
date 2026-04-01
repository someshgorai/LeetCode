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
    void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &locus) {
        if (!root) return;

        if (root->left) {
            mapping(root->left, locus);
            locus[root->left] = root;
        }

        if (root->right) {
            mapping(root->right, locus);
            locus[root->right] = root;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> locus;
        mapping(root, locus);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int curr_level = 0;
        while (!q.empty()) {
            int n = q.size();
            if (curr_level++ == k) break;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (locus[node] && !vis[locus[node]]) {
                    q.push(locus[node]);
                    vis[locus[node]] = true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};