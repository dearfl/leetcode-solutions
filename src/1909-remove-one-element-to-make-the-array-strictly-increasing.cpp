// Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.
//
// The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
//

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.clear();
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    vec.push_back(nums[j]);
                }
            }
            bool flag = true;
            for (int j = 1; j < vec.size(); j++) {
                if (vec[j-1] >= vec[j]) {
                    flag = false;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};
