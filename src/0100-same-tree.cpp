// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<pair<TreeNode*, TreeNode*>> dq;
        dq.emplace_back(p, q);
        while (!dq.empty()) {
            auto [a, b] = dq.front();
            dq.pop_front();
            if (a && b) {
                if (a->val != b->val) {
                    return false;
                }
                dq.emplace_back(a->left, b->left);
                dq.emplace_back(a->right, b->right);
            } else if (a || b) {
                return false;
            }
        }
        return true;
    }
};
