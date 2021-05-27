// Given an integer array nums and two integers k and t, return true if
// there are two distinct indices i and j in the array such that abs(nums[i] -
// nums[j]) <= t and abs(i - j) <= k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            auto pos = window.lower_bound((long long)nums[i] - t);
            if (pos != window.end() && *pos - nums[i] <= t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
