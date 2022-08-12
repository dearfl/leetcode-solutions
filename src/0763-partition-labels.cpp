/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

Example 1:
    Input: s = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
        The partition is "ababcbaca", "defegde", "hijhklij".
        This is a partition so that each letter appears in at most one part.
        A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:
    Input: s = "eccbbbbdec"
    Output: [10]

Constraints:
    1 <= s.length <= 500
    s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int end[256] = { 0 };
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            end[s[i]] = i + 1;
        }
        int i = 0;
        while (i < s.length()) {
            int r = i + 1, l = i;
            while (i < r) {
                r = max(r, end[s[i]]);
                i++;
            }
            res.push_back(r - l);
        }
        return res;
    }
};
