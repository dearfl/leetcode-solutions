/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Example 1:
    Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    Output: 2
    Explanation:
        The two tuples are:
        1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
        2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:
    Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
    Output: 1

Constraints:
    n == nums1.length
    n == nums2.length
    n == nums3.length
    n == nums4.length
    1 <= n <= 200
    -22^8 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 22^8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> cnt, cnt2, cnt3;
        for (auto e : nums1) {
            cnt[e]++;
        }
        for (auto e : nums2) {
            for (auto [k, v] : cnt) {
                cnt2[k + e] += v;
            }
        }
        for (auto e : nums3) {
            for (auto [k, v] : cnt2) {
                cnt3[k + e] += v;
            }
        }
        int ans = 0;
        for (auto e : nums4) {
            ans += cnt3[-e];
        }
        return ans;
    }
};

class BetterSolution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        map<int, int> cnt;
        for (auto e1 : nums1) {
            for (auto e2 : nums2) {
                cnt[e1 + e2]++;
            }
        }
        for (auto e1 : nums3) {
            for (auto e2 : nums4) {
                ans += cnt[-e1 - e2];
            }
        }
        return ans;
    }
};
