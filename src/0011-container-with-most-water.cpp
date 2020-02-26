// // Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Example:
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49
//
//

// naive O(n^2) solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 1; i < height.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (res < min(height[i], height[j]) * (i - j)) {
                    res = min(height[i], height[j]) * (i - j);
                }
            }
        }
        return res;
    }
};

// O(n) solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, res = 0;
        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
