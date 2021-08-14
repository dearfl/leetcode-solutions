// In a garden represented as an infinite 2D grid, there is an apple tree planted at every integer coordinate. The apple tree planted at an integer coordinate (i, j) has |i| + |j| apples growing on it.
//
// You will buy an axis-aligned square plot of land that is centered at (0, 0).
//
// Given an integer neededApples, return the minimum perimeter of a plot such that at least neededApples apples are inside or on the perimeter of that plot.
//

class Solution {
public:
    long long minimumPerimeter(long long n) {
        long long l = 1, r = 1e5;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if ((2 * mid * (mid- 1) * (2 * mid - 1)) < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return 4 * (2 * l - 2);
    }
};
