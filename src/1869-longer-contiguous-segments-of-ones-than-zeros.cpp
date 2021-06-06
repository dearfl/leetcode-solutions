// Given a binary string s, return true if the longest contiguous segment
// of 1s is strictly longer than the longest contiguous segment of 0s in
// s. Return false otherwise.
//
// For example, in s = "110100010" the longest contiguous segment of 1s has
// length 2, and the longest contiguous segment of 0s has length 3.
// Note that if there are no 0s, then the longest contiguous segment of 0s is
// considered to have length 0. The same applies if there are no 1s.
//

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ml1 = 0, ml0 = 0, length = 0;
        char last = '1';
        for (int i = 0; i < s.length(); i++) {
            if (last == s[i]) {
                length++;
            } else {
                if (last == '1') {
                    ml1 = max(ml1, length);
                } else {
                    ml0 = max(ml0, length);
                }
                length = 1;
            }
            last = s[i];
            if (last == '1') {
                ml1 = max(ml1, length);
            } else {
                ml0 = max(ml0, length);
            }
        }
        return ml1 > ml0;
    }
};
