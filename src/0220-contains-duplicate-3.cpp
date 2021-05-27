// Given an integer array nums and two integers k and t, return true if
// there are two distinct indices i and j in the array such that abs(nums[i] -
// nums[j]) <= t and abs(i - j) <= k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // set as slide window because set is sorted and support o(logn)
        // insert/erase/find... operations
        // since we search first and insert later, we don't need use multiset,
        // since finding the exact value in set means we definitly found an
        // answer
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                // keep the set size less or equal than k
                window.erase(nums[i - k - 1]);
            }
            // x >= nums[i] - t <=> x - nums[i] >= -t
            auto pos = window.lower_bound((long long)nums[i] - t);
            // x - nums[i] <= t so -t <= x - nums[i] <= t
            // => | x - nums[i] | <= t
            if (pos != window.end() && *pos - nums[i] <= t) {
                return true;
            }
            // don't forget to insert nums[i] after search
            window.insert(nums[i]);
        }
        return false;
    }
};
