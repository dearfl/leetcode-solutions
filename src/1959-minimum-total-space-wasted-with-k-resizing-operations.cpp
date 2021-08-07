// You are currently designing a dynamic array. You are given a 0-indexed integer array nums, where nums[i] is the number of elements that will be in the array at time i. In addition, you are given an integer k, the maximum number of times you can resize the array (to any size).
//
// The size of the array at time t, sizet, must be at least nums[t] because there needs to be enough space in the array to hold all the elements. The space wasted at time t is defined as sizet - nums[t], and the total space wasted is the sum of the space wasted across every time t where 0 <= t < nums.length.
//
// Return the minimum total space wasted if you can resize the array at most k times.
//
// Note: The array can have any size at the start and does not count towards the number of resizing operations.

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size(), dp[201][201], mv = 0, s = 0;
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                dp[i][j] = i <= j ? 0 : INT_MAX;
            }
        }
        for (int i = 0; i < n; i++) {
            mv = max(mv, nums[i]);
            s += nums[i];
            dp[i][0] = mv * (i + 1) - s;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                if (nums[j] != nums[j - 1]) {
                    int mm = nums[j], ss = 0;
                    for (int k = j; k > 0; k--) {
                        mm = max(mm, nums[k]);
                        ss += nums[k];
                        dp[j][i] = min(dp[j][i], dp[k-1][i-1] + mm * (j - k + 1) - ss);
                    }
                } else {
                    int mm = nums[j], ss = 0;
                    for (int k = j; k > 0; k--) {
                        mm = max(mm, nums[k]);
                        ss += nums[k];
                        dp[j][i] = min(dp[j][i], dp[k-1][i] + mm * (j - k + 1) - ss);
                    }
                }
            }
        }
        return dp[n - 1][k];
    }
};
