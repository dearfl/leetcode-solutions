// Given the head of a singly linked list, return true if it is a palindrome.
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

// no need for o(n) space approach IMO
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        auto *p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            if (vec[i] != vec[j]) {
                return false;
            }
        }
        return true;
    }
};
