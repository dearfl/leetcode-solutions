// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//
// Return the sorted array.
//

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto n : nums) {
            cnt[n]++;
        }
        sort(nums.begin(), nums.end(), [&cnt](int a, int b) { return cnt[a] == cnt[b] ? a > b : cnt[a] < cnt[b]; });
        return nums;
    }
};
