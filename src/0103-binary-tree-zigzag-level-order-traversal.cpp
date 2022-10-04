/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]
Example 2:
    Input: root = [1]
    Output: [[1]]
Example 3:
    Input: root = []
    Output: []

Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> _q, tmp;
        _q.push(root);
        int idx = 0;
        while (!_q.empty()) {
            ans.push_back({});
            while (!_q.empty()) {
                auto n = _q.front();
                _q.pop();
                if (!n) {
                    continue;
                }
                ans.back().push_back(n->val);
                tmp.push(n->left);
                tmp.push(n->right);
            }
            if (idx % 2 == 1) {
                reverse(ans.back().begin(), ans.back().end());
            }
            swap(_q, tmp);
            idx++;
        }
        ans.pop_back();
        return ans;
    }
};
