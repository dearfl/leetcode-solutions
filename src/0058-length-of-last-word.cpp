// Given a string s consists of some words separated by spaces, return the
// length of the last word in the string. If the last word does not exist,
// return 0.
//
// A word is a maximal substring consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            ret = tmp.length();
        }
        return ret;
    }
};
