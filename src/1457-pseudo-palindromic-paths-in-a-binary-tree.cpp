/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:
    Input: root = [2,3,1,3,1,null,1]
    Output: 2
    Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:
    Input: root = [2,1,1,1,3,null,null,null,null,null,1]
    Output: 1
    Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:
    Input: root = [9]
    Output: 1

Constraints:
    The number of nodes in the tree is in the range [1, 10^5].
    1 <= Node.val <= 9
*/

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
    bool isp(int cnt[]) {
        int res = 0;
        for (int i = 0; i < 10; i++) {
            if (cnt[i] % 2 == 1) {
                res++;
            }
        }
        return res < 2;
    }

    int helper(TreeNode *node, int cnt[]) {
        cnt[node->val]++;
        int res = 0;
        if (!node->left && !node->right) {
            res += isp(cnt);
        }
        if (node->left) {
            res += helper(node->left, cnt);
        }
        if (node->right) {
            res += helper(node->right, cnt);
        }
        cnt[node->val]--;
        return res;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        int cnt[10] = { 0 };
        return helper(root, cnt);
    }
};

// a very concise solution by lee215
// basic idea: at most 1 digit has odd occurrence
// use bit vector to check whether above condition is true
class SolutionByLee215 {
    int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if (!root) return 0;
        // count => each bit i represents whether number i is odd
        // we dont need to revert this change before return because count is passed by value
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        // if root is leaf node and at most 1 bit is 1
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
};
