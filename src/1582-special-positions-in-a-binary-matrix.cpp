// Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, return the number of special positions in mat.
//
// A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
//
//

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.back().size(), ans = 0;
        for (int i = 0; i < m; i++) {
            int idx = -1, cnt = 0, s = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    idx = j;
                    cnt++;
                }
            }
            if (cnt == 1) {
                for (int k = 0; k < m; k++) {
                    s += mat[k][idx];
                }
                if (s == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
