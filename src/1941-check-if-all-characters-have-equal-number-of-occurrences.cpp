// Given a string s, return true if s is a good string, or false otherwise.
//
// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
//

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = { 0 };
        for (const auto c : s) {
            cnt[c - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                if (count == 0) {
                    count = cnt[i];
                } else {
                    if (count != cnt[i]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
