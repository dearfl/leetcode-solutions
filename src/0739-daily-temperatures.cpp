/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
Example 2:
    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]
Example 3:
    Input: temperatures = [30,60,90]
    Output: [1,1,0]

Constraints:
    1 <= temperatures.length <= 10^5
    30 <= temperatures[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// My naive and complicate O(N) solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }
        set<int> _set;
        int v = pq.top().first;
        vector<int> tmp;
        while (!pq.empty()) {
            auto [e, k] = pq.top();
            pq.pop();
            if (v != e) {
                for (auto x : tmp) {
                    _set.insert(x);
                }
                tmp.clear();
            }
            tmp.push_back(k);
            auto it = _set.upper_bound(k);
            if (it != _set.end()) {
                ans[k] = *it - k;
            }
            v = e;
        }
        return ans;
    }
};

// Clean Solution by sparklethinker O(N) time ? and O(1) space
class CleanSolution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                j = res[j] > 0 ? res[j] + j : temperatures.size();
            }
            // either j == size || temperatures[j] > temperatures[i]
            if (j < temperatures.size()) {
                res[i] = j - i;
            }
        }
        return res;
    }
};
