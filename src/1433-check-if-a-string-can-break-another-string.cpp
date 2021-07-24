// Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.
//
// A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int cnt1[26] = { 0 }, cnt2[26] = { 0 }, count1 = 0, count2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        bool t1 = true, t2 = true;
        for (int i = 0; i < 26; i++) {
            count1 += cnt1[i];
            count2 += cnt2[i];
            t1 = t1 && count1 >= count2;
            t2 = t2 && count2 >= count1;
        }
        return t1 || t2;
    }
};
