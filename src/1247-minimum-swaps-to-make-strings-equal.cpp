// You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].
//
// Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.
//


class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length(), c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            s1[i] == 'x' ? c1++ : c2++;
        }
        return c1 % 2 == c2 % 2 ? c1 / 2 + c2 / 2 + c1 % 2 + c2 % 2 : -1;
    }
};
