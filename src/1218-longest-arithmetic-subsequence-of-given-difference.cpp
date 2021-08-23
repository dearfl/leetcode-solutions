// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
//
// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
//

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), 1);
        unordered_map<int, int> index;
        int ans = 0;
        index[arr[0]] = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (index.find(arr[i]) != index.end()) {
                dp[i] = max(dp[i], dp[index[arr[i]]]);
            }
            if (index.find(arr[i] - d) != index.end()) {
                dp[i] = max(dp[i], dp[index[arr[i] - d]] + 1);
            }
            ans = max(ans, dp[i]);
            index[arr[i]] = i;
        }
        return ans;
    }
};
