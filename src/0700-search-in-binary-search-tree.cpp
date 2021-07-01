// You are given the root of a binary search tree (BST) and an integer val.
//
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        return searchBST(root->val > val ? root->left : root->right, val);
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        auto p = root;
        while (p) {
            if (p->val == val) {
                break;
            } else if (p->val > val) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        return p;
    }
};
