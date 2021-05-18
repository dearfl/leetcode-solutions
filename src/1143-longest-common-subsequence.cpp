// Given two strings text1 and text2, return the length of their longest
// common subsequence. If there is no common subsequence, return 0.
//
// A subsequence of a string is a new string generated from the original
// string with some characters (can be none) deleted without changing the
// relative order of the remaining characters.
//
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both
// strings.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        int dp[1024][1024];
        for (int i = 0; i <= text1.length(); i++) {
            for (int j = 0; j <= text2.length(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

