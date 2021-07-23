// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
//

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dx = c[0][0] - c[1][0], dy = c[0][1] - c[1][1];
        for (int i = 1; i < c.size(); i++) {
            if (dx * (c[i][1] - c[i-1][1]) != dy * (c[i][0] - c[i-1][0])) {
                return false;
            }
        }
        return true;
    }
};
