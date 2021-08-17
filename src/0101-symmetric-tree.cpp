// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
//
//

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            auto ln = q.front(); q.pop();
            auto rn = q.front(); q.pop();
            if (ln && !rn || !ln && rn || ln && rn && ln->val != rn->val) {
                return false;
            }
            if (ln) {
                q.push(ln->left);
                q.push(rn->right);
                q.push(ln->right);
                q.push(rn->left);
            }
        }
        return true;
    }
};
