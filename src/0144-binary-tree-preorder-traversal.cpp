// Given the root of a binary tree, return the preorder traversal of its
// nodes' values.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 left(left), right(right) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode *node, vector<int> &vec) {
        if (node == nullptr) {
            return;
        }
        vec.emplace_back(node->val);
        helper(node->left, vec);
        helper(node->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        helper(root, preorder);
        return preorder;
    }
};
