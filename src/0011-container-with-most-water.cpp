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
