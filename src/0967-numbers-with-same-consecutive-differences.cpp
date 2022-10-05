/*
Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

Example 1:
    Input: n = 3, k = 7
    Output: [181,292,707,818,929]
    Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:
    Input: n = 2, k = 1
    Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Constraints:
    2 <= n <= 9
    0 <= k <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i < 10; i++) {
            queue<int> _q;
            _q.push(i);
            for (int j = 1; j < n; j++) {
                int z = _q.size();
                for (int m = 0; m < z; m++) {
                    int a = _q.front();
                    _q.pop();
                    int d = a % 10;
                    if (d + k < 10) {
                        _q.push(a * 10 + d + k);
                    }
                    if (k != 0 && 0 <= d - k) {
                        _q.push(a * 10 + d - k);
                    }
                }
            }
            while (!_q.empty()) {
                ans.push_back(_q.front());
                _q.pop();
            }
        }
         return ans;
    }
};
