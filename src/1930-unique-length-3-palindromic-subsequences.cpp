// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
//
// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
//
// A palindrome is a string that reads the same forwards and backwards.
//
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//
// For example, "ace" is a subsequence of "abcde".

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<vector<int>> idx(26);
        for (int i = 0; i < s.length(); i++) {
            idx[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (idx[i].size() < 2 || idx[j].empty()) {
                    continue;
                }
                int l = idx[i].front(), r = idx[i].back();
                auto it1 = upper_bound(idx[j].begin(), idx[j].end(), l);
                auto it2 = lower_bound(idx[j].begin(), idx[j].end(), r);
                if (it1 != it2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
