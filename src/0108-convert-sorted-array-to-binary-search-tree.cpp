// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

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
    TreeNode* helper(vector<int>::iterator first, vector<int>::iterator last) {
        if (first == last) {
            return nullptr;
        }
        if (first + 1 == last) {
            return new TreeNode(*first);
        }
        auto mid = first + (last - first) / 2;
        auto left = helper(first, mid), right = helper(mid + 1, last);
        return new TreeNode(*mid, left, right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums.begin(), nums.end());
    }
};
