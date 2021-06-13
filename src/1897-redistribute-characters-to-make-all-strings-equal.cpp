// You are given an array of strings words (0-indexed).
//
// In one operation, pick two distinct indices i and j, where words[i] is a
// non-empty string, and move any character from words[i] to any position in
// words[j].
//
// Return true if you can make every string in words equal using any number
// of operations, and false otherwise.

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> count;
        for (auto &s : words) {
            for (const auto &c : s) {
                count[c]++;
            }
        }
        for (auto &[k, v] : count) {
            if (v % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};
