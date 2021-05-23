// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

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

// recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *n = head->next, *k = reverseList(n);
        n->next = head;
        head->next = nullptr; // !important
        return k;
    }
};

// iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head, *n = head->next;
        while (n) {
            ListNode *nn = n->next;
            n->next = p;
            p = n;
            n = nn;
        }
        head->next = nullptr;
        return p;
    }
};
