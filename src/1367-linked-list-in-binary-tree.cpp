// Given a binary tree root and a linked list with head as the first node. 
//
// Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
//
// In this context downward path means a path that starts at some node and goes downwards.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// slow recursive solution, will TLE
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (root->val == head->val) {
            if (isSubPath(head->next, root->left) || isSubPath(head->next, root->right)) {
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// correct recursive solution
class Solution {
public:
    bool helper(ListNode *head, TreeNode *root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        return head->val == root->val && (helper(head->next, root->left) || helper(head->next, root->right));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (root->val == head->val) {
            if (helper(head->next, root->left) || helper(head->next, root->right)) {
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
