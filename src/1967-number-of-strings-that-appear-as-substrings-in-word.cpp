// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
//
// A substring is a contiguous sequence of characters within a string.

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (const auto s : patterns) {
            if (word.find(s) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};
