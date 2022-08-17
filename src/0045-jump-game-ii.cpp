/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:
    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
    Input: nums = [2,3,0,1,4]
    Output: 2

Constraints:
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

// DP Solution: time O(NM) space O(N) where N=10000, M=1000, could do better
class DPSolution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < min(i + nums[i] + 1, (int)nums.size()); j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

// BFS Solution: time O(N), space O(1)
class BFSSolution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 1, step = 0;
        while (end < nums.size()) {
            int reach = end;
            for (int i = start; i < end; i++) {
                reach = max(reach, i + nums[i] + 1);
            }
            step++;
            start = end;
            end = reach;
        }
        return step;
    }
};
