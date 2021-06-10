// Given the root of a binary tree and two integers val and depth, add a row
// of nodes with value val at the given depth depth.
//
// Note that the root node is at depth 1.
//
// The adding rule is:
//
// Given the integer depth, for each not null tree node cur at the depth depth
// - 1, create two tree nodes with value val as cur's left subtree root and
// right subtree root.
// cur's original left subtree should be the left subtree of the new left
// subtree root.
// cur's original right subtree should be the right subtree of the new right
// subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a
// tree node with value val as the new root of the whole original tree, and
// the original tree is the new root's left subtree.
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
    TreeNode *helper(TreeNode *root, int val, int depth, bool left = true) {
        TreeNode *n;
        if (depth == 1) {
            n = new TreeNode(val);
            if (left) {
                n->left = root;
            } else {
                n->right = root;
            }
            return n;
        }
        if (root) {
            n = helper(root->left, val, depth - 1, true);
            root->left = n;
            n = helper(root->right, val, depth - 1, false);
            root->right = n;
        }
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root, val, depth);
    }
};

// compact c++ solution of others
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 0 || d == 1) {
            TreeNode* newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root && d >= 2) {
            root->left  = addOneRow(root->left,  v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
};
