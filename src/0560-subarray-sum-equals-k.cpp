/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2
Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2

Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

// 使用hash表记录序列[0..]的和的个数
// 在后续的遍历中，通过查找hash表内符合要求的和的个数
// 来确定有多少个序列符合要求
// sum -> sum([0..i])
// K = sum - target
// 通过哈系表查出和为target的[0..]序列的个数，这就是以i结束和为K的[j..i]序列的个数
// 时间复杂度O(N)，O(N^2)方案会超时
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int sum = 0, res = 0;
        // 减去[0..0]也是合法的
        um[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int target = sum - k;
            if (um.find(target) != um.end()) {
                res += um[target];
            }
            um[sum]++;
        }
        return res;
    }
};
