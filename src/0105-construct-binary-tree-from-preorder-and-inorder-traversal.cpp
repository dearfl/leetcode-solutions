// Given two integer arrays preorder and inorder where preorder is the
// preorder traversal of a binary tree and inorder is the inorder traversal of
// the same tree, construct and return the binary tree.
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
    TreeNode* buildTreeImpl(vector<int>::iterator pre_first, vector<int>::iterator in_first, vector<int>::iterator in_last) {
        auto length = in_last - in_first;
        if (length < 1) {
            return nullptr;
        }
        int pivot = *pre_first;
        auto mid = find(in_first, in_last, pivot);
        TreeNode *res = new TreeNode(pivot);
        res->left = buildTreeImpl(pre_first + 1, in_first, mid);
        res->right = buildTreeImpl(pre_first + 1 + (mid - in_first), mid + 1, in_last);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeImpl(preorder.begin(), inorder.begin(), inorder.end());
    }
};
