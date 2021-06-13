// Given a string s, reverse only all the vowels in the string and return
// it.
//
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
// cases.

class Solution {
public:
    bool isVowels(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isVowels(s[l])) l++;
            while (l < r && !isVowels(s[r])) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
