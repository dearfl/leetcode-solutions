// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
//
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//
//
class Solution {
public:
    string reverseStr(string s, int k) {
        auto it = s.begin();
        while (it < s.end()) {
            reverse(it, min(it + k, s.end()));
            it += 2 * k;
        }
        return s;
    }
};
