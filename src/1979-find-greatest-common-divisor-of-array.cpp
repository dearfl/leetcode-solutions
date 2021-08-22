// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
//
// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

class Solution {
public:
    int gcd(int a, int b) {
        return a % b ? gcd(b, a % b) : b;
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums.front(), nums.back());
    }
};
