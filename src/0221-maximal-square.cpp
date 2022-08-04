/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4
Example 2:
    Input: matrix = [["0","1"],["1","0"]]
    Output: 1
Example 3:
    Input: matrix = [["0"]]
    Output: 0

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.
*/

// straight forward solution using prefix sum
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat.back().size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + mat[i][j] - '0';
            }
        }
        for (int k = min(m, n); k > 0; k--) {
            for (int i = 0; i + k < m + 1; i++) {
                for (int j = 0; j + k < n + 1; j++) {
                    if (ps[i+k][j+k] - ps[i][j+k] - ps[i+k][j] + ps[i][j] == k * k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
};

// dp solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat.back().size(), res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != '1') {
                    continue;
                }
                dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
                res = max(dp[i+1][j+1], res);
            }
        }
        return res * res;
    }
};
