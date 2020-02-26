// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 // Example:
 //
 // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 // Output: 7 -> 0 -> 8
 // Explanation: 342 + 465 = 807.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0, v1, v2;
        ListNode *res = new ListNode(0), *p = res;
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        res->val = sum % 10;
        do {
            l1 = l1 ? l1->next : nullptr, l2 = l2 ? l2->next : nullptr;
            if (!l1 && !l2) break;
            v1 = l1 ? l1->val : 0;
            v2 = l2 ? l2->val : 0;
            sum = v1 + v2 + carry;
            carry = sum / 10;
            p->next = new ListNode(0);
            p->next->val = sum % 10;
            p = p->next;
        } while (true);
        if (carry) {
            p->next = new ListNode(0);
            p->next->val = carry;
        }
        return res;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(0), *p = dummy;
        while (l1 || l2) {
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p->next = new ListNode(carry % 10);
            carry /= 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            p = p->next;
        }
        if (carry) {
            p->next = new ListNode(carry);
        }
        return dummy->next;
    }
};


