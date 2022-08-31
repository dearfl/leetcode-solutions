/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
Example 2:
    Input: s = "a"
    Output: [["a"]]

Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool is_palindrome(string &s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void dfs(string &s, int i, vector<string> &col, vector<vector<string>> &ans) {
        if (i >= s.size()) {
            ans.push_back(col);
            return;
        }
        for (auto j = i; j < s.size(); j++) {
            if (is_palindrome(s, i, j)) {
                col.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, col, ans);
                col.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> ans;
        dfs(s, 0, tmp, ans);
        return ans;
    }
};
