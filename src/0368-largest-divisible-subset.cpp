/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

Example 1:
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
Example 2:
    Input: nums = [1,2,4,8]
    Output: [1,2,4,8]

Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i] <= 2 * 10^9
    All the integers in nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, pair<int, int>> _map;
        int max_ = 1, last = nums[0];
        for (auto e : nums) {
            _map[e] = {1, -1};
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (_map[nums[i]].first < _map[nums[j]].first + 1) {
                        _map[nums[i]] = {_map[nums[j]].first + 1, nums[j]};
                        if (_map[nums[i]].first > max_) {
                            max_ = _map[nums[i]].first;
                            last = nums[i];
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (last != -1) {
            ans.push_back(last);
            last = _map[last].second;
        }
        return ans;
    }
};
