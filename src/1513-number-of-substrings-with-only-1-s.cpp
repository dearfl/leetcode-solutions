// Given a binary string s (a string consisting only of '0' and '1's).
//
// Return the number of substrings with all characters 1's.
//
// Since the answer may be too large, return it modulo 10^9 + 7.
//

class Solution {
    public:
        int numSub(string s) {
            int res = 0, count = 0;
            for (const auto c : s) {
                count = c == '1' ? count + 1 : 0;
                res = (res + count) % 1000000007;
            }
            return res;
        }
};
