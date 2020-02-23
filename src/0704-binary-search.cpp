class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l != nums.size() && nums[l] == target) {
            return l;
        }
        return -1;
    }
};

// use std lib
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto pos = lower_bound(nums.begin(), nums.end(), target);
        if (pos < nums.end() && *pos == target) return pos - nums.begin();
        return -1;
    }
};
