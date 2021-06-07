// Given an array of integers arr and an integer target.
//
// You have to find two non-overlapping sub-arrays of arr each with a sum
// equal target. There can be multiple answers so you have to find an answer
// where the sum of the lengths of the two sub-arrays is minimum.
//
// Return the minimum sum of the lengths of the two required sub-arrays, or
// return -1 if you cannot find such two sub-arrays.
//

class Solution {
public:
int minSumOfLengths(vector<int>& arr, int target) {
    vector<int> prefix(arr.size() + 1, INT_MAX), suffix(arr.size() + 1, INT_MAX), ps(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        ps[i + 1] = ps[i] + arr[i];
    }
    for (int i = 0; i < ps.size(); i++) {
        int j = lower_bound(ps.begin() + i, ps.end(), ps[i] + target) - ps.begin();
        if (j != ps.size() && ps[j] == ps[i] + target) {
            prefix[j] = min(prefix[j], j - i);
            suffix[i] = min(suffix[i], j - i);
        }
    }
    for (int i = 1; i < ps.size(); i++) {
        prefix[i] = min(prefix[i], prefix[i - 1]);
        suffix[ps.size() - i - 1] = min(suffix[ps.size() - i - 1], suffix[ps.size() - i]);
    }
    long long sum = INT_MAX;
    for (int i = 0; i < ps.size(); i++) {
        sum = min(sum, (long long)prefix[i] + suffix[i]);
    }
    return sum == INT_MAX ? -1 : sum;
}
};

// o(n) solution with DP, very nice solution by Pjdope
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> dp(arr.size(), INT_MAX);
        int currsum = 0, ans = INT_MAX, l = 0, r = 0, len = INT_MAX;
        while (r < arr.size()) {
            currsum += arr[r];
            while (currsum > target) {
                currsum -= arr[l++];
            }
            if (currsum == target) {
                if (l > 0 && dp[l-1] != INT_MAX) {
                    ans = min(ans, dp[l - 1] + r - l + 1);
                }
                len = min(len, r - l + 1);
            }
            dp[r++] = len;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
