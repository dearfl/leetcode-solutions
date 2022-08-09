/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.

Example 1:
  Input: nums = [3,2,3]
  Output: 3
Example 2:
  Input: nums = [2,2,1,1,1,2,2]
  Output: 2

Constraints:
  n == nums.length
  1 <= n <= 5 * 10^4
  -10^9 <= nums[i] <= 10^9
*/

// o(n) time, o(n) space
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> um;
        for (auto num : nums) {
            um[num]++;
        }
        int maxk = 0, maxv = 0;
        for (auto [k, v] : um) {
            if (maxv < v) {
                maxv = v;
                maxk = k;
            }
        }
        return maxk;
    }
};

// o(n) time, o(1) space
// keep track of two counts
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int k[2] = {0, 0}, c[2] = {0, 0};
        for (auto num : nums) {
            int i1 = c[0] > c[1] ? 0 : 1;
            int i2 = 1 - i1;
            if (k[i1] == num) {
                c[i1]++;
            } else if (k[i2] == num) {
                c[i2]++;
            } else {
                k[i2] = num;
                c[i2] = 1;
            }
        }
        return c[0] > c[1] ? k[0] : k[1];
    }
};

// o(n) time, o(1) space, Moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int idx = 0, count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                idx = i;
                count = 1;
            } else if (nums[idx] == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return nums[idx];
    }
};
