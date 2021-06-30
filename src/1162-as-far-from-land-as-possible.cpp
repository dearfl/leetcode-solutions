// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//
// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
//

class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int ans = -1, n = grid.size();
        vector<pair<int, int>> di = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        deque<pair<int, int>> dq, tmp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    dq.emplace_back(i, j);
                }
            }
        }

        while (!dq.empty()) {
            ans++;
            while (!dq.empty()) {
                auto [y, x] = dq.front();  // don't use auto &[y, x] = dq.front(); here
                dq.pop_front();
                for (const auto &[dy, dx] : di) {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[ny][nx] == 0) {
                        grid[ny][nx] = 1;
                        tmp.emplace_back(ny, nx);
                    }
                }
            }
            swap(dq, tmp);
        }
        return ans ? ans : -1;
    }
};
