// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.
//
// Follow up: Could you implement a solution using only O(1) extra space
// complexity and O(n) runtime complexity?
//

// sum solution, be ware of overflow
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n * (n + 1) / 2;
        for (const auto &e: nums) {
            sum -= e;
        }
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n * (n + 1) / 2;
        return sum - accumulate(nums.begin(), nums.end(), 0);
    }
};

// bit manipulation solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // init result as n, think it as result = 0 ^ n;
        int result = nums.size(), i = 0;
        for (const auto &e : nums) {
            result ^= e;
            result ^= i++;
        }
        return result;
    }
};
