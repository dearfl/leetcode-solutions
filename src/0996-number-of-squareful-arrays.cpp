// Given an array nums of non-negative integers, the array is squareful if for
// every pair of adjacent elements, their sum is a perfect square.
//
// Return the number of permutations of nums that are squareful.  Two
// permutations perm1 and perm2 differ if and only if there is some index i
// such that perm1[i] != perm2[i].
//

class Solution {
public:
    int helper(vector<int> nums, int p = -1, int res = 0) {
        if (p == nums.size() - 1) {
            return 1;
        }
        unordered_set<int> s;
        for (auto i = p + 1; i < nums.size(); ++i) {
            if (s.insert(nums[i]).second) {
                int n = p >= 0 ? sqrt(nums[i] + nums[p]) : 0;
                if (p == -1 || n * n == nums[i] + nums[p]) {
                    swap(nums[i], nums[p + 1]);
                    res += helper(nums, p + 1);
                }
            }
        }
        return res;
    }

    int numSquarefulPerms(vector<int>& nums) {
        return helper(nums);
    }
};
