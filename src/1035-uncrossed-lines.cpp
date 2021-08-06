// We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
//
// Now, we may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
//
// nums1[i] == nums2[j];
// The line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.
//
// Return the maximum number of connecting lines we can draw in this way.
//

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n)), index(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
            }
            dp[i][0] = max(i == 0 ? 0 : dp[i-1][0], dp[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (nums2[i] == nums1[0]) {
                dp[0][i] = 1;
            }
            dp[0][i] = max(i == 0 ? 0 : dp[0][i-1], dp[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = A[i] == B[i] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
}
