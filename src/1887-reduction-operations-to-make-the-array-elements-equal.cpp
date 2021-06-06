// Given an integer array nums, your goal is to make all elements in nums
// equal. To complete one operation, follow these steps:
//
// 1. Find the largest value in nums. Let its index be i (0-indexed) and its
// value be largest. If there are multiple elements with the largest value,
// pick the smallest i.
// 2. Find the next largest value in nums strictly smaller than largest. Let its
// value be nextLargest.
// 3. Reduce nums[i] to nextLargest.
// Return the number of operations to make all elements in nums equal.
//

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0, i = 0;
        while (i < nums.size()) {
            while (i < nums.size() && (i == 0 || nums[i] == nums[i-1])) {
                i++;
            }
            if (i != nums.size()) {
                res += i;
            }
            i++;
        }
        return res;
    }
};
