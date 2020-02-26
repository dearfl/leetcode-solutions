// // Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.

// Example 1:
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Example 3:
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".

// Example 4:
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

// Example 5:
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false
//
//

//Recursion solution
class Solution {
public:
    bool isMatch(string s, string p) {
        char c;
        if (p.empty()) {
            return s.empty();
        }
        if (p.length() > 1 && p[1] == '*') {
            if (isMatch(s, p.substr(2))) {
                return true;
            } else if (s.length() > 0 && (p[0] == '.' || p[0] == s[0])) {
                return isMatch(s.substr(1), p);
            }
        } else if (s.length() > 0 && (p[0] == '.' || p[0] == s[0])) {
            return isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }
};

//DP solution
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        int m = s.length(), n = p.length();
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i > 1 && p[i-1] == '*' && dp[0][i-2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
                }
            }
        }
        return dp[m][n];
    }
};
