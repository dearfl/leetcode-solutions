// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).
//
// For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
// You are given a sentence s and an integer k. You want to truncate s such that it contains only the first k words. Return s after truncating it.

ass Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        while (k > 0 && i < s.length()) {
            if (s[i] == ' ') {
                k--;
            }
            i++;
        }
        return i == s.length() ? s.substr(0, i) : s.substr(0, i - 1);
    }
};
