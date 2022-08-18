/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
Example 2:
    Input: root = [1]
    Output: [[1]]
Example 3:
    Input: root = []
    Output: []

Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> dq, tmp;
        dq.push(root);
        while (!dq.empty()) {
            vector<int> tvec;
            while (!dq.empty()) {
                auto p = dq.front();
                dq.pop();
                if (p) {
                    tvec.push_back(p->val);
                    tmp.push(p->left);
                    tmp.push(p->right);
                }
            }
            swap(dq, tmp);
            if (!tvec.empty()) {
                res.push_back(tvec);
            }
        }
        return res;
    }
};
