// You have a list of points in the plane. Return the area of the largest
// triangle that can be formed by any 3 of the points.


class Solution {
public:
    double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        double l1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double l2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        double l3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        double p = (l1 + l2 + l3) / 2;
        return sqrt(p * (p - l1) * (p - l2) * (p - l3));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 2; i < points.size(); i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 0; k < j; k++) {
                    ans = max(ans, area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }
        return ans;
    }
};
