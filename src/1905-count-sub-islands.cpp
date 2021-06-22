// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
//
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
//
// Return the number of islands in grid2 that are considered sub-islands.

class Solution {
public:
    void helper(vector<vector<int>>& grid, vector<pair<int, int>>& island, int x, int y) {
        int direction[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == 1) {
            grid[x][y] = 0;
            island.emplace_back(x, y);
            for (auto &[m, n] : direction) {
                helper(grid, island, x + m, y + n);
            }
        }
    }

    vector<vector<pair<int, int>>> getIslands(vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> ans;

        int count = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> island;
                    helper(grid, island, i, j);
                    ans.push_back(island);
                }
            }
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for (auto &vec : getIslands(grid2)) {
            bool flag = true;
            for (const auto &[x, y] : vec) {
                flag &= grid1[x][y];
            }
            count += flag;
        }
        return count;
    }
};
