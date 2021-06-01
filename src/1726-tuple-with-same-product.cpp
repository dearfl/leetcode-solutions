// Given an array nums of distinct positive integers, return the number of
// tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements
// of nums, and a != b != c != d.
//

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> multi;
        int res = 0, m;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                m = nums[i] * nums[j];
                res += multi[m]++;
            }
        }
        return res * 8;
    }
};
