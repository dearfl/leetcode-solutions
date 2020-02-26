/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// recursive solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        } else {
            ListNode *tmp = head->next;
            head->next = swapPairs(head->next->next);
            tmp->next = head;
            return tmp;
        }
    }
};
