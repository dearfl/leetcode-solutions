// Given an n x n binary matrix grid, return the length of the shortest clear
// path in the matrix. If there is no clear path, return -1.
//
// A clear path in a binary matrix is a path from the top-left cell (i.e.,
// (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//
//  - All the visited cells of the path are 0.
//  - All the adjacent cells of the path are 8-directionally connected (i.e.,
// they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> oq;
        set<pair<int, int>> open, close;
        if (grid[0][0] == 0) {
            oq.emplace(1, pair<int, int>{0, 0});
            open.emplace(0, 0);
        }
        while (!oq.empty()) {
            auto [v, pos] = oq.top();
            auto &[a, b] = pos;
            oq.pop();
            open.erase(pos);
            if (a == n - 1 && b == n - 1) {
                return v;
            }
            if (close.find(pos) == close.end()) {
                close.insert(pos);
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        int x = a + i, y = b + j;
                        if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 0 && close.find({x, y}) == close.end()) {
                            open.emplace(x, y);
                            oq.emplace(v + 1, pair<int, int>{x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> oq;
        set<pair<int, int>> open, close;
        vector<pair<int, int>> direction{{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};
        if (grid[0][0] == 0) {
            oq.emplace(1, pair<int, int>{0, 0});
            open.emplace(0, 0);
        }
        while (!oq.empty()) {
            auto [v, pos] = oq.top();
            auto &[a, b] = pos;
            oq.pop();
            open.erase(pos);
            if (a == n - 1 && b == n - 1) {
                return v;
            }
            if (close.find(pos) == close.end()) {
                close.insert(pos);
                for (auto &[i, j] : direction) {
                    int x = a + i, y = b + j;
                    if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 0 && close.find({x, y}) == close.end()  && open.find({x, y}) == open.end()) {
                        open.emplace(x, y);
                        oq.emplace(v + 1, pair<int, int>{x, y});
                    }
                }
            }
        }
        return -1;
    }
};
