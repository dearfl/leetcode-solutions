// You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
//
// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
//
// Return true if a and b are alike. Otherwise, return false.

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (isVowel(s[i])) {
                cnt1++;
            }
            if (isVowel(s[s.length() - i - 1])) {
                cnt2++;
            }
        }
        return cnt1 == cnt2;
    }
};
