// The minimum absolute difference of an array a is defined as the minimum value of |a[i] - a[j]|, where 0 <= i < j < a.length and a[i] != a[j]. If all elements of a are the same, the minimum absolute difference is -1.
//
// For example, the minimum absolute difference of the array [5,2,3,7,2] is |2 - 3| = 1. Note that it is not 0 because a[i] and a[j] must be different.
// You are given an integer array nums and the array queries where queries[i] = [li, ri]. For each query i, compute the minimum absolute difference of the subarray nums[li...ri] containing the elements of nums between the 0-based indices li and ri (inclusive).
//
// Return an array ans where ans[i] is the answer to the ith query.
//
// A subarray is a contiguous sequence of elements in an array.
//
// The value of |x| is defined as:
//
// x if x >= 0.
// -x if x < 0.
//

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> preSum(nums.size() + 1, vector<int>(101, 0));
        vector<int> cnt(101), ans;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j < 101; j++) {
                preSum[i][j] = preSum[i - 1][j];
            }
            preSum[i][nums[i - 1]]++;
        }
        for (auto &vec : queries) {
            int l = vec[0], r = vec[1] + 1;
            for (int i = 1; i < 101; i++) {
                cnt[i] = preSum[r][i] - preSum[l][i];
            }
            int m = INT_MAX, pre = -1;
            for (int i = 0; i < 101; i++) {
                if (cnt[i] == 0) continue;
                if (pre != -1) m = min(m, abs(i - pre));
                pre = i;
            }
            ans.push_back(m == INT_MAX ? -1 : m);
        }
        return ans;
    }
};
