// You are given an integer array nums consisting of n elements, and an
// integer k.
//
// Find a contiguous subarray whose length is equal to k that has the maximum
// average value and return this value. Any answer with a calculation error
// less than 10^-5 will be accepted.
//

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> s(nums.size() + 1, 0);
        double res = -1e30;
        for (int i = 0; i < nums.size(); i++) {
            s[i+1] = s[i] + nums[i];
        }
        for (int i = k; i < nums.size() + 1; i++) {
            res = max(res, 1.0 * (s[i] - s[i - k]) / k);
        }
        return res;
    }
};
