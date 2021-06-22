// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
//
// A substring is a contiguous sequence of characters within a string.
//

class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for (i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                break;
            }
        }
        return num.substr(0, i + 1);
    }
};
