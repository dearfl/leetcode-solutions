// Given the root of a binary tree, return the maximum width of the given tree.
//
// The maximum width of a tree is the maximum width among all levels.
//
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
//
// It is guaranteed that the answer will in the range of 32-bit signed integer.

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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> dq, swp;
        int ans = 0;
        dq.emplace_back(root, 1);
        while (!dq.empty()) {
            auto [_1, l1] = dq.front();
            auto [_2, l2] = dq.back();
            ans = max(ans, l2 - l1 + 1);
            while (!dq.empty()) {
                auto [node, idx] = dq.front();
                idx = idx - l1 + 1;
                dq.pop_front();
                if (node->left) {
                    swp.emplace_back(node->left, 2 * idx - 1);
                }
                if (node->right) {
                    swp.emplace_back(node->right, 2 * idx);
                }
            }
            swap(dq, swp);
        }
        return ans;
    }
};
