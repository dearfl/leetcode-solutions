// Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.
//
// Return abs(i - start).
//
// It is guaranteed that target exists in nums.

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int i = 0; start + i < nums.size() || start - i >= 0; i++) {
            if (start + i < nums.size() && nums[start + i] == target || start - i >= 0 && nums[start - i] == target) {
                return i;
            }
        }
        return -1;
    }
};
