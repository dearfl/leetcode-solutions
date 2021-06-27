// You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
//
// The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
//
// A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
// Return the matrix after applying k cyclic rotations to it.
//

class Solution {
public:
    int x1(int j, int a, int b) {
        return (0 <= j && j < b) ? 0 : b <= j && j <= a + b - 2 ? j - b + 1 : (a + b - 2 < j && j <= a + b * 2 - 3 ? a - 1 : 2 * a + 2 * b - j - 4);
    }

    int y1(int j, int a, int b) {
        return (0 <= j && j < b) ? j : b <= j && j <= a + b - 2 ? b - 1 : (a + b - 2 < j && j <= a + b * 2 - 3 ? a + 2 * b - j - 3 : 0);
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.front().size(), l = min(m, n);
        vector<vector<int>> ans = grid;
        for (int i = 0; i < l / 2; i++) {
            int a = m - i * 2, b = n - i * 2, c = a * 2 + b * 2 - 4;
            for (int j = 0; j < c; j++) {
                int x = i + x1(j, a, b);
                int y = i + y1(j, a, b);
                int s = i + x1((j + k) % c, a, b), f = i + y1((j + k) % c, a, b);
                ans[x][y] = grid[s][f];
            }
        }
        return ans;
    }
};
