// You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the average of its neighbors.
//
// More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].
//
// Return any rearrangement of nums that meets the requirements.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        int l = 0, r = (ans.size() + 1) / 2;
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = i % 2 ? nums[r++] : nums[l++];
        }
        return ans;
    }
};
