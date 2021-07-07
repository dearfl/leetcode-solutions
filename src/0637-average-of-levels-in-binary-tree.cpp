// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10^-5 of the actual answer will be accepted.

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
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode *> dq, swp;
        vector<double> ans;
        dq.push_back(root);
        long long sum = 0, cnt = 0;
        while (!dq.empty()) {
            sum = 0, cnt = 0;
            while (!dq.empty()) {
                auto node = dq.front();
                dq.pop_front();
                if (node) {
                    sum += node->val;
                    cnt++;
                    swp.push_back(node->left);
                    swp.push_back(node->right);
                }
            }
            if (cnt) {
                ans.push_back(1.0 * sum / cnt);
            }
            swap(dq, swp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode *> dq, swp;
        vector<double> ans;
        dq.push_back(root);
        long long sum = 0, cnt = 0;
        while (!dq.empty()) {
            sum = 0, cnt = 0;
            while (!dq.empty()) {
                auto node = dq.front();
                dq.pop_front();
                sum += node->val;
                cnt++;
                if (node->left) {
                    swp.push_back(node->left);
                }
                if (node->right) {
                    swp.push_back(node->right);
                }
            }
            ans.push_back(1.0 * sum / cnt);
            swap(dq, swp);
        }
        return ans;
    }
};
