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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode *> q;
        unordered_set<TreeNode *> lastLevel;
        unordered_map<TreeNode *, TreeNode *> relation;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                lastLevel.insert(node);
                if (node->left) {
                    q.push(node->left);
                    relation[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    relation[node->right] = node;
                }
            }
        }

        
        while (lastLevel.size() > 1) {
            unordered_set<TreeNode *>next;
            for (TreeNode *node:lastLevel) {
                next.insert(relation[node]);
            }
            lastLevel = next;
        }

        return *lastLevel.begin();
    }
};