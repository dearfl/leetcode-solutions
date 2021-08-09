// Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.
//
// A boomerang is a set of three points that are all distinct and not in a straight line.
//

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[1][0] - points[0][0], y1 = points[1][1] - points[0][1];
        int x2 = points[2][0] - points[1][0], y2 = points[2][1] - points[1][1];
        return x1 * y2 != x2 * y1;
    }
};
