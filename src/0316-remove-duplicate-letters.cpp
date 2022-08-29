/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
    Input: s = "bcabc"
    Output: "abc"
Example 2:
    Input: s = "cbacdcbc"
    Output: "acdb"

Constraints:
    1 <= s.length <= 10^4
    s consists of lowercase English letters.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> cnt(256), vis(256);
        for (auto c : s) {
            cnt[c]++;
        }
        for (auto c : s) {
            cnt[c]--;
            if (vis[c]) {
                continue;
            }
            while (!ans.empty() && c < ans.back() && cnt[ans.back()]) {
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            ans += c;
            vis[c] = 1;
        }
        return ans;
    }
};
