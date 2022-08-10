/*
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

Example 1:
    Input: root = [1,1,1,1,1,null,1]
    Output: true
Example 2:
    Input: root = [2,2,2,5,2]
    Output: false

Constraints:
    The number of nodes in the tree is in the range [1, 100].
    0 <= Node.val < 100
*/

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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        int val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p) {
                if (p->val != val) {
                    return false;
                }
                q.push(p->left);
                q.push(p->right);
            }
        }
        return true;
    }
};
