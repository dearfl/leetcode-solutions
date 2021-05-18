// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> s(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (s[i] <= 0) {
                s[i+1] = nums[i];
            } else {
                s[i+1] = nums[i] + s[i];
            }
        }
        return *max_element(s.begin() + 1, s.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> s(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            s[i+1] = max(nums[i], nums[i] + s[i]);
        }
        return *max_element(s.begin() + 1, s.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0], max_global = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_current = max(max_current + nums[i], nums[i]);
            max_global = max(max_global, max_current);
        }
        return max_global;
    }
};
