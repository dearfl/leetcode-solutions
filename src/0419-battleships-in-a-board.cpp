// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
//
// Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
//

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board.back().size();
        int ans = 0;
        int count = 0, single = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n; j++) {
                if ((j == n || board[i][j] == '.') && count > 0) {
                    ans++;
                    if (count == 1) {
                        ans--;
                        single += (i == 0 || board[i-1][j-1] == '.') && (i == m - 1 || board[i+1][j-1] == '.');
                    }
                    count = 0;
                } else if (j < n && board[i][j] == 'X') {
                    count++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if ((j == m || board[j][i] == '.') && count > 0) {
                    ans++;
                    if (count == 1) {
                        ans--;
                        single += (i == 0 || board[j-1][i-1] == '.') && (i == n - 1 || board[j-1][i+1] == '.');
                    }
                    count = 0;
                } else if (j < m && board[j][i] == 'X') {
                    count++;
                }
            }
        }
        return ans + single / 2;
    }
};
