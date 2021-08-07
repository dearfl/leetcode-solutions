// A fancy string is a string where no three consecutive characters are equal.
//
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
//
// Return the final string after the deletion. It can be shown that the answer will always be unique.
//
class Solution {
public:
    string makeFancyString(string s) {
        int count = 0;
        char cur = ' ';
        string ans = "";
        for (const char c : s) {
            if (c == cur && count == 2) {
                continue;
            }
            ans += c;
            count = c == cur ? count + 1 : 1;
            cur = c;
        }
        return ans;
    }
};
