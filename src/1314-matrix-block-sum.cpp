// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//
// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.
//

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 1; i < preSum.size(); i++) {
            for (int j = 1; j < preSum[i].size(); j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                int x1 = max(0, i - k), y1 = max(0, j - k);
                int x2 = min(m, i + k + 1), y2 = min(n, j + k + 1);
                ans[i][j] = preSum[x2][y2] - preSum[x1][y2] - preSum[x2][y1] + preSum[x1][y1];
            }
        }
        return ans;
    }
};
