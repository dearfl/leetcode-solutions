// Given an array nums of integers, you can perform operations on the
// array.
//
// In each operation, you pick any nums[i] and delete it to earn nums[i]
// points. After, you must delete every element equal to nums[i] - 1 or
// nums[i] + 1.
//
// You start with 0 points. Return the maximum number of points you can
// earn by applying such operations.
//

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> cnt, dp;
        for (const auto &n : nums) {
            cnt[n] += n;
        }
        vector<pair<int, int>> vec;
        for (const auto &p : cnt) {
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end());
        int lastk = 0, sk = 0;
        for (const auto &[k, v] : vec) {
            if (lastk + 1 < k) {
                dp[k] = dp[lastk] + v;
            } else {
                dp[k] = max(dp[lastk], dp[sk] + v);
            }
            sk = lastk;
            lastk = k;
        }
        int res = 0;
        for (const auto & [k, v] : dp) {
            res = max(res, v);
        }
        return res;
    }
};

// solution by alexander 
class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        vector<int> values(10001, 0);
        for (const auto &n : nums) {
            values[n] += n;
        }
        int take = 0, skip = 0;
        for (int i = 0; i < 10001; i++) {
            int tmp = max(skip + values[i], take);
            skip = take;
            take = tmp;
        }
        return take;
    }
}
