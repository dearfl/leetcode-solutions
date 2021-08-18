// You are given two binary trees root1 and root2.
//
// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
//
// Return the merged tree.
//
// Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) {
            return nullptr;
        }
        TreeNode *root = new TreeNode();
        root->val = (r1 ? r1->val : 0) + (r2 ? r2->val : 0);
        TreeNode *l1 = r1 ? r1->left : nullptr;
        TreeNode *l2 = r2 ? r2->left : nullptr;
        TreeNode *s1 = r1 ? r1->right : nullptr;
        TreeNode *s2 = r2 ? r2->right : nullptr;
        root->left = mergeTrees(l1, l2);
        root->right = mergeTrees(s1, s2);
        return root;
    }
};
