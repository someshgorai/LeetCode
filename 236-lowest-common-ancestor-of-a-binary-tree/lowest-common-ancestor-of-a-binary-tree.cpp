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
    bool ancestors(TreeNode* node, TreeNode* x, vector<TreeNode*> &parents) {
        parents.push_back(node);
        
        if (node->val == x->val) return true;

        if (node->left && ancestors(node->left, x, parents)) return true;
        
        if (node->right && ancestors(node->right, x, parents)) return true;
        
        parents.pop_back();

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_ancestor, q_ancestor;
        ancestors(root, p, p_ancestor);
        ancestors(root, q, q_ancestor);

        TreeNode* commAnces;
        auto it1 = p_ancestor.begin();
        auto it2 = q_ancestor.begin();

        while (it1 != p_ancestor.end() && it2 != q_ancestor.end()) {
            if (*it1 == *it2) commAnces = *it1;
            else break;
            it1++;
            it2++;
        }

        return commAnces;
    }
};