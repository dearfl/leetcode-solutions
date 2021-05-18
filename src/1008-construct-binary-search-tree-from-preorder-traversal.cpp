// Given an array of integers preorder, which represents the preorder
// traversal of a BST (i.e., binary search tree), construct the tree and
// return its root.
//
// It is guaranteed that there is always possible to find a binary search tree
// with the given requirements for the given test cases.
//
// A binary search tree is a binary tree where for every node, any descendant
// of Node.left has a value strictly less than Node.val, and any descendant of
// Node.right has a value strictly greater than Node.val.
//
// A preorder traversal of a binary tree displays the value of the node first,
// then traverses Node.left, then traverses Node.right.

class Solution {
public:
    TreeNode* bstFromPreorderImpl(vector<int>::iterator first, vector<int>::iterator last) {
        if (first >= last) {
            return nullptr;
        }
        int pivot = *first;
        auto mid = lower_bound(first + 1, last, pivot);
        TreeNode *res = new TreeNode(pivot);
        res->left = bstFromPreorderImpl(first + 1, mid);
        res->right = bstFromPreorderImpl(mid, last);
        return res;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorderImpl(preorder.begin(), preorder.end());
    }
};
