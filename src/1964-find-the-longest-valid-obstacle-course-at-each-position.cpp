// You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.
//
// For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:
//
// You choose any number of obstacles between 0 and i inclusive.
// You must include the ith obstacle in the course.
// You must put the chosen obstacles in the same order as they appear in obstacles.
// Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
// Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.
//

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int> ans, stk;
        for (const auto i : o) {
            auto it = upper_bound(stk.begin(), stk.end(), i);
            ans.push_back(it - stk.begin() + 1);
            if (it == stk.end()) {
                stk.push_back(i);
            } else {
                *it = i;
            }
        }
        return ans;
    }
};
