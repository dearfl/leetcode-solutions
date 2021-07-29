// G

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while (headA || headB) {
            if (headA) {
                if (s.find(headA) != s.end()) {
                    return headA;
                }
                s.insert(headA);
                headA = headA->next;
            }
            if (headB) {
                if (s.find(headB) != s.end()) {
                    return headB;
                }
                s.insert(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *a = headA, *b = headB;
        while (a) {
            n1++;
            a = a->next;
        }
        while (b) {
            n2++;
            b = b->next;
        }
        ListNode *p = n1 > n2 ? headA : headB, *q = n1 > n2 ? headB : headA;
        for (int i = 0; i < abs(n1 - n2); i++) {
            p = p->next;
        }
        while (p || q) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};
