// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//
// The following rules define a valid string:
//
// - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// - Any right parenthesis ')' must have a corresponding left parenthesis '('.
// - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

class Solution {
public:
    bool checkValidString(string s) {
        int minl = 0, maxl = 0;
        for (const auto c : s) {
            if (c == '(') {
                minl++, maxl++;
            } else if (c == ')') {
                minl = max(minl - 1, 0);
                maxl--;
            } else {
                minl = max(minl - 1, 0);
                maxl++;
            }
            if (maxl < 0) {
                return false;
            }
        }
        return minl == 0;
    }
};
