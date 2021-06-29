// Given a 2D integer array matrix, return the transpose of matrix.
//
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
//

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
