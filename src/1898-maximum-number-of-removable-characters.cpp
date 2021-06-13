// You are given two strings s and p where p is a subsequence of s. You are also
// given a distinct 0-indexed integer array removable containing a
// subset of indices of s (s is also 0-indexed).
//
// You want to choose an integer k (0 <= k <= removable.length) such that,
// after removing k characters from s using the first k indices in
// removable, p is still a subsequence of s. More formally, you will mark the
// character at s[removable[i]] for each 0 <= i < k, then remove all marked
// characters and check if p is still a subsequence.
//
// Return the maximum k you can choose such that p is still a subsequence of s
// after the removals.
//
// A subsequence of a string is a new string generated from the original
// string with some characters (can be none) deleted without changing the
// relative order of the remaining characters.
//
//

// 一开始抱有侥幸心理，尝试暴力做，结果超时，快结束才意识到是二分题

class Solution {
public:
    bool helper(string s, string &p, vector<int> &removable, int k) {
        for (int i = 0; i < k; i++) {
            s[removable[i]] = ' ';
        }
        int pi = 0;
        for (int i = 0; pi < p.length() && i < s.length(); i++) {
            if (s[i] == p[pi]) {
                pi++;
            }
        }
        return pi == p.length();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size() + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(s, p, removable, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return max(0, l - 1);
    }
};
