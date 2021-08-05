// You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:
//
// Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
// Remove the last element from the current array nums.
// Return an array answer, where answer[i] is the answer to the ith query.
//

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = 0, a = (1 << maximumBit) - 1;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            a ^= nums[i];
            ans[nums.size() - i - 1] = a ^ k;
        }
        return ans;
    }
};
