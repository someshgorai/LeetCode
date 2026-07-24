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
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    parents[node->left] = node;
                    q.push(node->left);
                }

                if (node->right) {
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        getParents(root, parents);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;

        while(!q.empty()) {
            if (level == k) break;
            level++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
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

                if (parents[node] && !vis[parents[node]]){
                    q.push(parents[node]);
                    vis[parents[node]] = true;
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