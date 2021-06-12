// In a string s of lowercase letters, these letters form consecutive groups
// of the same character.
//
// For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx",
// "z", and "yy".
//
// A group is identified by an interval [start, end], where start and end
// denote the start and end indices (inclusive) of the group. In the above
// example, "xxxx" has the interval [3,6].
//
// A group is considered large if it has 3 or more characters.
//
// Return the intervals of every large group sorted in increasing order
// by start index.

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int startIdx = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i != s.length() && (i == 0 || s[i] == s[i - 1])) {
                continue;
            }
            if (i - startIdx > 2) {
                res.push_back({startIdx, i - 1});
            }
            startIdx = i;
        }
        return res;
    }
};
