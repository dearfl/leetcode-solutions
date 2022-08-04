/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
        -1 + 1 + 1 + 1 + 1 = 3
        +1 - 1 + 1 + 1 + 1 = 3
        +1 + 1 - 1 + 1 + 1 = 3
        +1 + 1 + 1 - 1 + 1 = 3
        +1 + 1 + 1 + 1 - 1 = 3
Example 2:
    Input: nums = [1], target = 1
    Output: 1

Constraints:
    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000
*/

// naive solution get TLE when nums.size() == 20
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int bits = 0, n = nums.size(), ans = 0;
        while (bits < (1 << n)) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (bits & (1 << i)) {
                    res += nums[i];
                } else {
                    res -= nums[i];
                }
            }
            if (res == target){
                ans++;
            }
            bits++;
        }
        return ans;
    }
};


// dp solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp;
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back(unordered_map<int, int>());
            if (i == 0) {
                dp[i][nums[i]] += 1; // += because num[i] might equal to 0
                dp[i][-nums[i]] += 1;
            } else {
                for (auto [k, v] : dp[i - 1]) {
                    dp[i][k + nums[i]] += v;
                    dp[i][k - nums[i]] += v;
                }
            }
        }
        return dp.back()[target];
    }
};

// more concise dp solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size() + 1);
        dp[0][0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (auto [k, v] : dp[i - 1]) {
                dp[i+1][k + nums[i]] += v;
                dp[i+1][k - nums[i]] += v;
            }
        }
        return dp.back()[target];
    }
};
