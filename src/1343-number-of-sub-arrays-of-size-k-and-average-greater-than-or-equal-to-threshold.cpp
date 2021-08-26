// Given an array of integers arr and two integers k and threshold.
//
// Return the number of sub-arrays of size k and average greater than or equal to threshold.
//

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = accumulate(arr.begin(), arr.begin() + k, 0);
        int ans = sum >= threshold * k;
        for (int i = k; i < arr.size(); i++) {
            sum = sum + (arr[i] - arr[i - k]);
            ans += sum >= threshold * k;
        }
        return ans;
    }
};
