// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
//
// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
//
// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
//

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int h = maze.size(), w = maze.back().size(), x = entrance[1], y = entrance[0];
        maze[y][x] = '*';
        deque<int> dq, swp;
        int di[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int ans = 0;
        dq.push_back(y * w + x);
        while (!dq.empty()) {
            ans++;
            while (!dq.empty()) {
                int k = dq.front();
                dq.pop_front();
                int m = k / w, n = k % w;
                for (auto [a, b] : di) {
                    int s = m + a, d = n + b;
                    if (0 <= s && s < h && 0 <= d && d < w) {
                        if (maze[s][d] == '.') {
                            maze[s][d] = '*';
                            if (s == 0 || s == h - 1 || d == 0 || d == w - 1) {
                                return ans;
                            }
                            swp.push_back(s * w + d);
                        }
                    }
                }
            }
            swap(dq, swp);
        }
        return -1;
    }
};
