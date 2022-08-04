/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
        [
          1->4->5,
          1->3->4,
          2->6
        ]
        merging them into one sorted list: 1->1->2->3->4->4->5->6
Example 2:
    Input: lists = []
    Output: []
Example 3:
    Input: lists = [[]]
    Output: []
 
Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 10^4.
*/

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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode dummy, *p = &dummy;
        auto cmp = [](auto p1, auto p2) { return p1.first > p2.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, i});
            }
        }
        while (!pq.empty()) {
            auto [_, idx] = pq.top();
            pq.pop();
            p->next = lists[idx];
            lists[idx] = lists[idx]->next;
            if (lists[idx]) {
                pq.push({lists[idx]->val, idx});
            }
            p = p->next;
        }
        return dummy.next;
    }
};

// more nature solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode dummy, *p = &dummy;
        auto cmp = [](auto n1, auto n2) { return n1->val > n2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            auto n = pq.top();
            pq.pop();
            p->next = n;
            n = n->next;
            if (n) {
                pq.push(n);
            }
            p = p->next;
        }
        return dummy.next;
    }
};
