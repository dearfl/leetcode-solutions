/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        if (!l2) { return l1; }
        ListNode* minNode = l1->val < l2->val ? l1 : l2;
        ListNode* maxNode = l1->val < l2->val ? l2 : l1;
        minNode->next = mergeTwoLists(minNode->next, maxNode);
        return minNode;
    }
};
