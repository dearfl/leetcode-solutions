class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int curRow = 0, delta = -1;
        for (char c : s) {
            rows[curRow] += c;
            (curRow == 0 || curRow == numRows - 1) && (delta = -delta);
            curRow += delta;
        }
        string ret;
        for (string row : rows) {
            ret += row;
        }
        return ret;
    }
};
